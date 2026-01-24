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

ListNode* returnMiddleNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}


class Solution {
public:
bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    ListNode* mid = returnMiddleNode(head);
    ListNode* second = reverseList(mid);

    ListNode* first = head;
    ListNode* temp = second;

    while (temp != NULL) {
        if (first->data != temp->data) {
            return false;
        }
        first = first->next;
        temp = temp->next;
    }

    return true;
}

};


int main(){
    int n;
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for(int i = 0; i < n; i++){
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

    Solution sol;
    if(sol.isPalindrome(head)){
        cout << "Palindrome";
    }else{
        cout << "Not Palindrome";
    }

    return 0;
}
