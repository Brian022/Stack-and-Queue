#include <iostream>

using namespace std;

template<typename T>
class Stack;

template<typename T>
class Node
{
    private:
    Node<T> *sgte;
    T data;

    public:
    Node(T data){this->data = data;}

    friend class Stack<T>;
};

template<typename T>
class Stack
{
    private:
    Node<T> *top;
    Node<T> *actual;
    int tam =1;
    public:

    Stack()
    {
        top = NULL;
    }
    ~Stack()
    {
        while(!vacio())
            pop();
    }
    bool vacio()
    {
        if(top == NULL)
             return true;
        return false;

    }
    int tamano()
    {
        return tam;
    }

    void push(T data)
    {
        Node<T> *newTop = new Node<T>(data);
        if(top==NULL)
        {
            top = newTop;
        }
        else
        {
            newTop->sgte=top;
        }
        top=newTop;
    }

    void pop()
    {

        Node<T> *actual =top;
        top=actual->sgte;
        delete actual;
        tam-=1;
        return;
    }
    void mostrar()
    {
        while(!vacio())
        {
            cout<<top->data;
            pop();
        }
    }

};

int main()
{
    Stack<int> a;
    a.push(5);
    a.push(9);
    a.push(7);
    a.tamano();
    a.mostrar();
    a.tamano();


    return 0;
}
