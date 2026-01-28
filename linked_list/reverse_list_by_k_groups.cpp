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


ListNode* reverseList(ListNode* head, int k){
    if(head == NULL || k == 1){
        return head;
    }

    ListNode dummy(0);
    dummy.next = head;

    ListNode* grpPrev = &dummy;

    while(true){
        ListNode* temp = grpPrev;
        for(int i=0;i<k;i++){
            temp = temp->next;
            if(temp==NULL){
                return dummy.next;
            }
        }
        ListNode* grpNext = temp->next;
        ListNode* prev = grpNext;
        ListNode* curr = grpPrev->next;

        for(int i=0;i<k;i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* oldHead = grpPrev->next;
        grpPrev->next = temp;
        grpPrev = oldHead;
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

    int k;
    cin>>k;
    ListNode* temp = reverseList(head,k);
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}