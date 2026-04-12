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



int helper(TreeNode* root, int maxSoFar){
    if(root==NULL) return 0;
    int good = (root->val>=maxSoFar) ? 1 : 0;
    maxSoFar = max(maxSoFar, root->val);
    return good + helper(root->left, maxSoFar) + helper(root->right, maxSoFar);
}

int goodNodes(TreeNode* root){
    return helper(root, INT_MIN);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right =  new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(1);
    cout<<goodNodes(root)<<endl;
    return 0;
}