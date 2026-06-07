#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int>q;
    q.push(1);
    cout<<q.front()<<"enter"<<endl;
    q.push(12);
    cout<<q.front();
    return 0;
}