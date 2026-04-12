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


long long sum = INT_MIN;

int helper(TreeNode* root){
    if(root==NULL) return 0;
    int leftGain = max(helper(root->left),0);
    int rightGain = max(helper(root->right),0);
    sum = max(sum , (long long)(leftGain+root->val+rightGain));
    return root->val+max(leftGain, rightGain);
}

int maxPathSum(TreeNode* root){
    helper(root);
    return sum;
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
    cout<<maxPathSum(root)<<endl;
    return 0;
}

