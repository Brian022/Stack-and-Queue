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
    int tam = 0;
    public:

    Cola()
    {
        first = NULL;
    }
    ~Cola()
    {
        /*******************************
        Node<T> *temp=first;
        Node<T> *temp1;
        while(temp->sgte != NULL)
        {
            temp = temp->sgte;
            temp1 = temp;
            delete temp;
            if(temp->sgte == NULL)
            {
                delete temp;
            }

        *********************************/
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
    void mTamano(int x){    tam+=x;    }
    void meTamano(int x){   tam-=x;    }
    int Size(){  return tam;  }

    void push(T data)
    {
        mTamano(1);

        if(first == NULL)
        {
            Node<T> *nuevofirst = new Node<T>(data);
            first = nuevofirst;
        }
        else
        {
            Node<T> *actual = first;
            while(actual->sgte != NULL){actual = actual->sgte;}
            actual->sgte = new Node<T>(data);
        }


    }

    void pop()
    {
        if(!vacio())
        {
        Node<T> *temp = first;
        first = temp->sgte;
        delete temp;
        meTamano(1);
        }

    }
    void mostrar()
    {
        Node<T> *actual = first;

            while(actual != NULL)
            {
                cout<<actual->data<<endl;
                actual = actual->sgte;

            }

    }

};

int main()
{
    Cola<int> a;
    a.vacio();
    a.push(5);
    a.push(10);
    a.push(15);
    a.mostrar();
    cout<<a.Size();
    cout<<"----\n";
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.mostrar();
    cout<<a.Size();

    return 0;
}
