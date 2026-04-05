#include<bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};


Node* connect(Node* root){
    if(!root) return NULL;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            auto node = q.front();
            q.pop();
            if(i==size-1) node->next = NULL;
            else node->next = q.front();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return root;
}

void printNext(Node* root){
    Node* levelStart = root;
    while(levelStart){
        Node* curr = levelStart;
        while(curr){
            cout << curr->val;
            if(curr->next) cout << " -> ";
            else cout << " -> NULL";
            curr = curr->next;
        }
        cout << endl;
        levelStart = levelStart->left; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(4);
    connect(root);
    printNext(root);
    return 0;
}