#include<iostream>
using namespace std;

class queue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    queue(int size) {
        this->size = size;   // ✅ fix
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int element) {
        if(rear == size) {   // ✅ fix
            cout << "Queue Overflow\n";
            return;
        }

        arr[rear] = element;
        cout << "Inserted at index " << rear << " : " << arr[rear] << endl;
        rear++;
    }

    void dequeue() {
        if(front == rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Removed from index " << front << " : " << arr[front] << endl;
        front++;

        // optional reset (good practice)
        if(front == rear) {
            front = 0;
            rear = 0;
        }
    }

    void isEmpty() {
        if(front == rear)
            cout << "Queue is Empty\n";
        else
            cout << "Queue is Not Empty\n";
    }

    void isFull() {
        if(rear == size)
            cout << "Queue is Full\n";
        else
            cout << "Queue is Not Full\n";
    }

    void getFront() {
        if(front == rear) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};

int main() {
    queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue();
    q.getFront();

    return 0;
}