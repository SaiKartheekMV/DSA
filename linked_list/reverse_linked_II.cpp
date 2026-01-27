#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

ListNode* reverseList(ListNode* head, int left, int right){
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode dummy(0);
    dummy.next = head;

    ListNode* prevLeft = &dummy;
    for(int i=0;i<left-1;i++){
        prevLeft = prevLeft->next;
    }

    ListNode* curr = prevLeft->next;
    ListNode* temp = curr->next;

    for(int i=0;i<right-left;i++){
        curr->next = temp->next;
        temp->next = prevLeft->next;
        prevLeft->next = temp;
        temp = curr->next;
    }

    return dummy.next;
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

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    int left , right;
    cin>>left>>right;

    ListNode* temp = reverseList(head, left, right);
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}