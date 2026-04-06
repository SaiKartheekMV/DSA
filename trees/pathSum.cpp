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


bool hasPath(TreeNode* root, int target){
    if(root==NULL) return false;
    if((root->left==NULL && root->right==NULL) && target==root->val ) return true;
    return hasPath(root->left, target-root->val) || hasPath(root->right, target-root->val);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right =  new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    int target;
    cin>>target;
    if(hasPath(root, target)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}