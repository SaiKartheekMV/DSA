#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
    int count;

public:
    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }

    void enqueue(int x) {
        if(isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        arr[rear] = x;
        rear = (rear + 1) % size;
        count++;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int val = arr[front];
        front = (front + 1) % size;
        count--;
        return val;
    }

    int peek() {
        if(isEmpty()) return -1;
        return arr[front];
    }
};