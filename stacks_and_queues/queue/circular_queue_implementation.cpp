#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int cap;

public:
    CircularQueue(int n){
        cap = n;
        arr = new int[cap];
        front = 0;
        rear = 0;
    }

    bool isEmpty(){
        return front == rear;
    }

    bool isFull(){
        return front == (rear+1)%cap;
    }

    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return ;
        }
        arr[rear] = x;
        rear = (rear + 1) % cap;
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty, Underflow alert"<<endl;
            return 0;
        }
        int val  = arr[front];
        front = (front+1) % cap;
        return val;
    }

    int peek(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
};