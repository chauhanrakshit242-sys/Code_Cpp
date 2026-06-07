#include<iostream>
using namespace std;
#define SIZE 100

class stack
{
    int arr[SIZE];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    void push(int element)
    {
       if(top==SIZE-1)
       {
         cout<<"overfolow";
       }
       top=top+1;
       arr[top]=element;
       cout<<"Element is inserted:"<<arr[top]<<endl;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is Underflow";
        }
            cout<<"Element is deleted:"<<arr[top]<<endl;
            top=top-1;
    }
    void empty()
    {
        if(top==-1)
        {
            cout<<"Stack is Empty";
        }
    }
    void peek()
    {
         cout<<"element on top: "<<arr[top]<<endl;
    }
    void isfull()
    {
        if(top==SIZE-1)
        {
            cout<<"Stack is full";
        }
    }
};
int main()
{
    stack s;
    s.push(2);
    s.push(4);
    s.peek();
    s.pop();
    s.peek();
    return 0;
}