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


ListNode* mergeList(ListNode* list1, ListNode* list2){
    ListNode dummy(-1);
    ListNode* curr = &dummy;

    while(list1!=NULL &&list2!=NULL){
        if(list1->data<=list2->data){
            curr->next = list1;
            list1 = list1->next;
        }else{
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if(list1!=NULL){
        curr->next = list1;
    }else{
        curr->next = list2;
    }
    return dummy.next;
}

int main(){
    int n1,n2;
    cin>>n1>>n2;


    ListNode* head1 = NULL;
    ListNode* tail1 = NULL;

    ListNode* head2 = NULL;
    ListNode* tail2 = NULL;

    for(int i=0;i<n1;i++){
        int x;
        cin>>x;

        ListNode* newNode = new ListNode(x);
        if(head1==NULL){
            head1 = newNode;
            tail1 = newNode;
        }else{
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    for(int i=0;i<n2;i++){
        int x;
        cin>>x;

        ListNode* newNode = new ListNode(x);
        if(head2==NULL){
            head2 = newNode;
            tail2 = newNode;
        }else{
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    ListNode* temp = mergeList(head1, head2);
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}