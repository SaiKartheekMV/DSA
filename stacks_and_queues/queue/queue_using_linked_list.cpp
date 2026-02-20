#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);

        if(isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int val = front->val;
        Node* temp = front;
        front = front->next;

        if(front == NULL) {  
            rear = NULL;
        }

        delete temp;
        return val;
    }

    int peek() {
        if(isEmpty()) return -1;
        return front->val;
    }
};