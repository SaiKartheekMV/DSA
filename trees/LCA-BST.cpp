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


TreeNode* leastCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==NULL) return NULL;
    if(p->val < root->val && q->val < root->val) return leastCommonAncestor(root->left, p, q);
    if(p->val > root->val && q->val > root->val) return leastCommonAncestor(root->right, p, q);
    return root;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);
    TreeNode* ans = leastCommonAncestor(root, p, q);
    cout<<ans->val<<endl;
    return 0;
}