#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:

    int data;
    ListNode* next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr!=NULL){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;

        ListNode* newNode = new ListNode(x);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseList(head);

    ListNode* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}