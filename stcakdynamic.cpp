#include<iostream>
using namespace std;

class Stack
{
    int* arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    // Push
    void push(int element)
    {
        if(top == capacity - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = element;
        cout << "Element inserted: " << arr[top] << endl;
    }

    // Pop
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Element deleted: " << arr[top] << endl;
        top--;
    }

    // Peek
    void peek()
    {
        if(top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    // isEmpty
    void isEmpty()
    {
        if(top == -1)
            cout << "Stack is Empty\n";
        else
            cout << "Stack is not Empty\n";
    }

    // isFull
    void isFull()
    {
        if(top == capacity - 1)
            cout << "Stack is Full\n";
        else
            cout << "Stack is not Full\n";
    }

    // Destructor (important)
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack s(10);

    s.push(2);
    s.push(4);
    s.peek();
    s.pop();
    s.peek();

    return 0;
}