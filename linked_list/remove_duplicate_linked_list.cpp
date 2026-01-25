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

ListNode* removeDuplicate(ListNode* head){
    ListNode* prev = head;
    ListNode* curr = head->next;

    if(head==NULL && head->next == NULL){
        return head;
    }
    while(curr!=NULL){
        if(prev->data == curr->data){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
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


    ListNode* temp = removeDuplicate(head);
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;

}