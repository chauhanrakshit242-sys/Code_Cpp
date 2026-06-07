#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int start = s;
    int end = e;

    while(start < end)
    {
        while(arr[start] <= pivot && start < e)
            start++;

        while(arr[end] > pivot)
            end--;

        if(start < end)
            swap(arr[start], arr[end]);
    }

    swap(arr[s], arr[end]);

    return end;
}

void Quicksort(int arr[], int s, int e)
{
    if(s >= e)
        return;

    int part = partition(arr, s, e);

    Quicksort(arr, s, part - 1);
    Quicksort(arr, part + 1, e);
}

int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int n = 5;

    Quicksort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}