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

int maxDepth(TreeNode* root){
    if(root == NULL) return 0;

    return 1+max(maxDepth(root->left), maxDepth(root->right));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    cout<<maxDepth(root)<<endl;
    return 0;
}

