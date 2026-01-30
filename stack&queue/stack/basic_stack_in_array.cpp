#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int top;
    int capacity;

    public:
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

     bool isEmpty(){
        return top == -1;
     }

     bool isFull(){
        return top == capacity;
     }

     void push(int val){
        if(isFull()) return;
        arr[++top] = val;
     }

     void pop(){
        if(isEmpty()) return;
        top--; 
     }

     int peek(){
        if(isEmpty()) return 0;
        return arr[top];
     }
};

int main(){
    int size;
    cin>>size;

    Stack s(size);

    int choice, value;
    while(true){
        cout<<"stack operations"<<endl;
        cout<<"Choose the following operations:- "<<endl;
        cout<<"1. Push Element"<<endl;
        cout<<"2. Pop Element"<<endl;
        cout<<"3. Top of Element"<<endl;
        cout<<"4. Exit Operations"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value:- ";
                cin>>value;
                s.push(value);
                break;
            case 2:
                s.pop();
                cout<<"Popped"<<endl;
                break;
            case 3:
                cout<<s.peek()<<endl;
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid choice\n";
        }
    }
    return 0;
}