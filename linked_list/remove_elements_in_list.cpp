#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode * next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

ListNode* removeElement(ListNode* head, int val){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;

    while(curr!= NULL){
        if(curr->data == val){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }

    head  = dummy->next;
    delete dummy;
    return head;
}


int main(){
    int n;
    cin >> n;
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int i=0; i<n; i++){
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

    int val;
    cin>>val;

    ListNode* temp = removeElement(head, val);
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;

}