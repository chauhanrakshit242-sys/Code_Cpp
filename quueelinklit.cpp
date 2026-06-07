#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // ENQUEUE
    void enqueue(int x) {
        Node* newNode = new Node(x);

        // empty queue
        if(rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // DEQUEUE
    void dequeue() {
        if(front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << "Removed: " << temp->data << endl;

        front = front->next;

        // if queue becomes empty
        if(front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // FRONT
    int getFront() {
        if(front == NULL) {
            return -1;
        }
        return front->data;
    }

    // ISEMPTY
    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.getFront() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front: " << q.getFront() << endl;

    return 0;
}