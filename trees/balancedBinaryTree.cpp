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

int height(TreeNode* root){
    int left = 0, right = 0;
    if(root==NULL) return 0;
    left = height(root->left);
    right = height(root->right);
    if(left==-1 || right ==-1) return -1;
    if(abs(left-right) > 1) return -1;
    return 1+max(left, right);
}

bool isBalanced(TreeNode* root){
    return height(root) != -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->left = new TreeNode(6);
    //root->left->left->left = new TreeNode(7);
    if(isBalanced(root)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}