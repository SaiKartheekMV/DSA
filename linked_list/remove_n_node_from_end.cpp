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

ListNode* removeNelement(ListNode* head, int n){
    ListNode dummy(-1);
    dummy.next = head;


    ListNode* slow = &dummy;
    ListNode* fast = &dummy;

    for(int i=0;i<=n;i++){
        fast = fast->next;
    }

    while(fast!=NULL){
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    
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

        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    int m;
    cin>>m;
    ListNode* temp = removeNelement(head, m);
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}