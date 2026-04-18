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


unordered_map<int, int>mp;


TreeNode* helper(vector<int>&preOrder, int preIndex, int left, int right){
    if(left > right) return NULL;
    TreeNode* root = new TreeNode(preOrder[preIndex]);
    int mid = mp[preOrder[preIndex]];
    root->left = helper(preOrder, preIndex+1, left, mid-1);
    root->right = helper(preOrder, preIndex+(mid-left)+1, mid+1, right);
    return root;
}

TreeNode* buildTree(vector<int>&preOrder, vector<int>&inOrder){
    for(int i=0;i<inOrder.size();i++){
        mp[inOrder[i]] = i;
    }
    int preIndex = 0;
    TreeNode* root = helper(preOrder, preIndex, 0, preOrder.size()-1);
    return root;
}


void printTree(TreeNode* root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n;
    cin>>m;
    vector<int>preorder(n);
    vector<int>inorder(m);
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    for(int i=0;i<m;i++){
        cin>>inorder[i];
    }
    TreeNode* root =  buildTree(preorder, inorder);
    printTree(root);
    return 0;
}