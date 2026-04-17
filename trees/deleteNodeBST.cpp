#include<bits/stdc++.h>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* helper(TreeNode* root){
    if(root==NULL) return NULL;
    while(!(root->left == NULL)){
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key){
    if(root==NULL) return NULL;
    if(key < root->val){
        root->left = deleteNode(root->left, key);
        return root;
    }
    if(key > root->val){
        root->right - deleteNode(root->right, key);
        return root;
    }

    if(root->left == NULL || root->right==NULL) return root->left? root->left : root->right;

    TreeNode* successor = helper(root->right);
    root->val = successor->val;
    root->right = deleteNode(root->right, successor->val);
    return root;
}

void printTree(TreeNode* root){
    if(root==NULL) return ;

    cout<<root->val<< " ";
    printTree(root->left);
    printTree(root->right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(7);
    int key;
    cin>>key;
    TreeNode* new_root = deleteNode(root, key);
    printTree(new_root);
    return 0;
}