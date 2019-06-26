#include <iostream>

using namespace std;

template<typename T>
class Cola;

template<typename T>
class Node
{
    private:
    Node<T> *sgte;
    T data;
    

    public:
    Node(T data){this->data = data;}

    friend class Cola<T>;
};

template<typename T>
class Cola
{
    private:
    Node<T> *first;
    Node<T> *actual;
    int tam =0;
    public:

    Cola()
    {
        first = NULL;
    }
    ~Cola()
    {
        while(!vacio())
        {
            pop();
        }
    }
    bool vacio()
    {
        if(first == NULL)
        {
            return true;
        }
        else
            return false;

    }
    
    int Size()
    {
        int tam = 0;
        Node<T> *actual = first;
        while(actual != NULL)
        {
             tam += 1;
            actual = actual->sgte;
        }
        return tam;
    }

    void push(T data)
    {

        Node<T> *nuevo = new Node<T>(data);

        if(first == NULL)
        {
            first = nuevo;
            first->sgte =NULL;
        }
        else
        {
            Node<T> *actual = first;
            while(actual->sgte != NULL){actual = actual->sgte;}
            actual->sgte = nuevo;
        }


    }

    void pop()
    {
        if(!vacio())
        {
            Node<T> *actual = first;
            first = first->sgte;
            delete actual;
            
        }



    }
    void mostrar()
    {
        Node<T> *actual = first;

            while(actual != NULL)
            {
                cout<<actual->data<< "-> ";
                actual = actual->sgte;
            }

    }

};

int main()
{
    Cola<int> a;
    a.push(5);
    a.push(7);
    a.mostrar();
    cout<<"Tamano = "<<a.Size()<<"\n";
    a.pop();
    a.pop();
    a.pop();
    a.push(4);
    a.mostrar();
    cout<<"Tamano = "<<a.Size()<<"\n";
    a.pop();
    a.push(3);
    a.push(7);
    a.pop();
    a.mostrar();
    cout<<"Tamano = "<<a.Size()<<"\n";



    return 0;
}
