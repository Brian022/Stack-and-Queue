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
    int tam =1;
    public:

    Cola(T data)
    {
        first = new Node<T>(data);
    }
    ~Cola()
    {
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

        }
    }
    bool vacio()
    {
        if(first == NULL)
            return true;
        return false;

    }
    int tamano()
    {
        return tam;
    }
    void push(T data)
    {

            Node<T> *actual = first;
            while(actual->sgte != NULL){actual = actual->sgte;}
            actual->sgte = new Node<T>(data);
            tam +=1;

    }

    void pop()
    {
        Node<T> *temp = first;
        first = first->sgte;
        tam-=1;
        delete temp;
        return;
    }

};
int main()
{
    Cola<int> a(5);
    a.vacio();
    a.push(9);
    a.push(5);
    a.push(10);
    a.tamano();
    a.pop();
    a.tamano();

    return 0;
}
