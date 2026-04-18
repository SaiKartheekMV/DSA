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

TreeNode* helper(vector<int>&postorder, int posIndex, int left, int right){
    if(left > right || posIndex < 0) return NULL;
    TreeNode* root = new TreeNode(postorder[posIndex]);
    int mid = mp[postorder[posIndex]];
    root->right = helper(postorder, posIndex-1, mid+1, right);
    root->left = helper(postorder, posIndex-1-(right-mid), left, mid-1);
    return root;
}

TreeNode* buildTree(vector<int>&inorder, vector<int>&postorder){
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]] = i;
    }
    int postIndex = postorder.size()-1;
    TreeNode* root = helper(postorder, postIndex, 0, postorder.size()-1);
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
    int n;
    int m;
    cin>>n;
    vector<int>inorder(n);
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    cin>>m;
    vector<int>postorder(m);
    for(int i=0;i<m;i++){
        cin>>postorder[i];
    }
    TreeNode* root = buildTree(inorder, postorder);
    printTree(root);
    return 0;
}