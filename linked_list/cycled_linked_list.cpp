#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<ListNode*> nodes;
    ListNode *head = nullptr, *tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ListNode *node = new ListNode(x);
        nodes.push_back(node);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int pos;
    cin >> pos;

    if (pos >= 0 && pos < n) {
        tail->next = nodes[pos];
    }

    if (hasCycle(head)) cout << "Yes cycle is there";
    else cout << "No cycle";

    return 0;
}
