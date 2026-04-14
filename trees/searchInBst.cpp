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


TreeNode *searchBST(TreeNode* root, int val){
    if(root==NULL) return NULL;
    if(root->val == val) return root;
    if(val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

void printBST(TreeNode* root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    printBST(root->left);
    printBST(root->right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    int val;
    cin>>val;
    TreeNode* result = searchBST(root, val);
    printBST(result);
    return 0;
}