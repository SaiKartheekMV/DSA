#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* partition(ListNode* head, int x) {
    ListNode* dummyL = new ListNode(-1);
    ListNode* dummyR = new ListNode(-1);

    ListNode* left = dummyL;
    ListNode* right = dummyR;

    ListNode* curr = head;

    while (curr != nullptr) {

        // Save the next node before changing curr->next
        ListNode* temp = curr->next;

        if (curr->val < x) {
            left->next = curr;
            left = left->next;
        }
        else {
            right->next = curr;
            right = right->next;
        }

        // Disconnect curr from the original list
        curr->next = nullptr;

        // Move to the next original node
        curr = temp;
    }

    // Connect left chain to right chain
    left->next = dummyR->next;

    return dummyL->next;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        ListNode* node = new ListNode(value);

        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    int x;
    cin >> x;

    head = partition(head, x);

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << '\n';

    return 0;
}