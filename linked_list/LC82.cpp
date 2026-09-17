#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev2 = dummy;
    ListNode* prev1 = head;
    ListNode* curr = head->next;

    while (curr != nullptr) {
        if (prev1->data == curr->data) {
            while (curr != nullptr && prev1->data == curr->data) {
                curr = curr->next;
            }

            prev2->next = curr;
            prev1 = curr;

            if (prev1 != nullptr) {
                curr = prev1->next;
            }
        } 
        else {
            prev2 = prev1;
            prev1 = curr;
            curr = curr->next;
        }
    }

    head = dummy->next;
    delete dummy;

    return head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* node = new ListNode(x);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    head = deleteDuplicates(head);

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << '\n';

    return 0;
}