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

ListNode* rotateList(ListNode* head, int k){
    if (head == NULL || head->next == NULL || k == 0){
        return head;
    }

    ListNode* tail = head;
    int n = 1;
    while(tail->next!=NULL){
        tail = tail->next;
        n++;
    }

    tail->next = head;

    k = k%n;

    ListNode* newTail = head;
    for(int i=0;i<n-k-1;i++){
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
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

    int k;
    cin>>k;

    ListNode* temp = rotateList(head, k);
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}