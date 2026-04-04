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


TreeNode * invertTree(TreeNode* root){
    if(root==NULL) return NULL;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

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
    cin.tie(NULL), cout.tie(NULL);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    invertTree(root);
    printTree(root);
    return 0;
}