#include<bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void push(int x) {
        if (isFull()) return;
        arr[++rear] = x;
    }

    void pop() {
        if (isEmpty()) return;
        front++;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};



int main() {
    int size;
    cout << "Enter queue capacity: ";
    cin >> size;

    Queue q(size);

    int choice, value;

    while (true) {
        cout << "Queue Operations";
        cout << "1. Push (Enqueue)\n";
        cout << "2. Pop (Dequeue)\n";
        cout << "3. Peek (Front)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.push(value);
                break;

            case 2:
                q.pop();
                cout << "Dequeued from queue\n";
                break;

            case 3:
                cout << "Front element: " << q.peek() << endl;
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
