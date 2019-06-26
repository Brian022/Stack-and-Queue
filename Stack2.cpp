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
        if(!vacio())
        {
            Node<T> *actual =top;
            top=top->sgte;
            delete actual;
        }
    }

    void mostrar()
    {
        Node<T> *actual = top;
        while(actual != NULL)
        {
            cout<<actual->data<<endl;
            actual = actual->sgte;
        }
    }

};

int main()
{
    Stack<int> a;

    a.push(5);
    a.mostrar();
    cout<<"\n-------\n";
    a.pop();
    a.pop();

    a.push(7);
    a.mostrar();
    cout<<"\n-------\n";
    a.push(9);
    a.push(8);
    a.pop();
    a.mostrar();




    return 0;
}
