#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap()
    {
        arr[0]=-1;
        size=0;
    }
    void insert(int val)
    {   
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
    void deleteNode()
    {
        if(size==0)
        {
            cout<<"Nothing to delete"<<endl;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size)
        {
            int leftIndex=2*i;
            int rightIndex=2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex])
            {
                swap(arr[i],arr[leftIndex]);
                i=leftIndex;
            }
            else if(rightIndex <size && arr[i]<arr[rightIndex])
            {
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
    }
    void heapifymethod(int arr[],int n ,int i)
    {
        int largest =i;
        int left=2*i;
        int right=2*i+1;
        if(left<n&&&arr[largest]<arr[left])
        {
            largest=left;
        }
        if(right<&&arr[lagest]<arr[right])
        {
            largest=right;
        }
        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        
    }
};
int main()
{
  heap h1;
  h1.insert(56);
  h1.insert(12);
  h1.insert(30);
  h1.insert(50);
  h1.insert(70);
  h1.print();
  h1.deleteNode();
  h1.print();
  return 0;
}