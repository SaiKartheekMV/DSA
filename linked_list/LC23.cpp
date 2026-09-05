#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
int data;
ListNode* next;

ListNode(int val){
    data = val;
    next = nullptr;
}

};

class Compare{
public:
bool operator()(ListNode* a, ListNode* b){
return a->data > b->data;
}
};

ListNode* solve(vector<ListNode*>& lists){
priority_queue<ListNode*, vector<ListNode*>, Compare> pq;


for(ListNode* head : lists){
    if(head != nullptr){
        pq.push(head);
    }
}

ListNode* dummy = new ListNode(0);
ListNode* tail = dummy;

while(!pq.empty()){
    ListNode* curr = pq.top();
    pq.pop();

    if(curr->next){
        pq.push(curr->next);
    }

    tail->next = curr;
    tail = curr;
}

return dummy->next;


}

ListNode* createList(vector<int>& arr){
if(arr.empty()){
return nullptr;
}


ListNode* head = new ListNode(arr[0]);
ListNode* tail = head;

for(int i = 1; i < arr.size(); i++){
    tail->next = new ListNode(arr[i]);
    tail = tail->next;
}

return head;


}

void printList(ListNode* head){
while(head != nullptr){
cout << head->data;


    if(head->next != nullptr){
        cout << " -> ";
    }

    head = head->next;
}

cout << '\n';


}

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);


int k;
cin >> k;

vector<ListNode*> lists(k);

for(int i = 0; i < k; i++){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int j = 0; j < n; j++){
        cin >> arr[j];
    }

    lists[i] = createList(arr);
}

ListNode* result = solve(lists);

printList(result);

return 0;


}
    