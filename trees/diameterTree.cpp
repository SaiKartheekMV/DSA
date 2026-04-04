#include<bits/stdc++.h>
using namespace std;

int diameter;

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


int dfs(TreeNode* root){
    if(root == NULL) return 0;

    int left = dfs(root->left);
    int right = dfs(root->right);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}


int diameterOfTree(TreeNode* root){
    dfs(root);
    return diameter;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(7);
    cout<<diameterOfTree(root)<<endl;
    return 0;
}