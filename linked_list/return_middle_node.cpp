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




ListNode* returnMiddleNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

int main(){
    int n;
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        ListNode* newNode = new ListNode(x);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    ListNode* ans = returnMiddleNode(head);
    if(ans != NULL){
        cout<<ans->data<<endl;
    }else{
        cout<<"No Middle for the given Linked list"<<endl;
    }
    return 0;
}