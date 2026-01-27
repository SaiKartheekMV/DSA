#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return NULL;

    ListNode* pA = headA;
    ListNode* pB = headB;

    while (pA != pB) {
        pA = (pA == NULL) ? headB : pA->next;
        pB = (pB == NULL) ? headA : pB->next;
    }
    return pA;
}

int main() {
    ListNode* common = new ListNode(8);
    common->next = new ListNode(9);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = common;

    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(5);
    headB->next->next = common;

    ListNode* ans = getIntersectionNode(headA, headB);

    if (ans)
        cout << ans->val << endl;
    else
        cout << -1 << endl;

    return 0;
}
