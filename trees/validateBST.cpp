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
long long min_val = LONG_MIN;
long long max_val = LONG_MAX;
bool helper(TreeNode* root, long long min_val, long long max_val){
    if(root==NULL) return true;
    if(root->val<= min_val || root->val>=max_val) return false;
    return helper(root->left, min_val, root->val) && helper(root->right, root->val, max_val);
}

bool validateBST(TreeNode* root){
    return helper(root, min_val, max_val);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    if(validateBST(root)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}