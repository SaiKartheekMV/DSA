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

int pathCount = 0;
unordered_map<long long, int>seen;

void helper(TreeNode* root, long long currSum, int targetSum){
    if(root==NULL) return ;
    currSum+=root->val;
    pathCount+=seen[currSum-targetSum];
    seen[currSum]++;
    helper(root->left, currSum, targetSum);
    helper(root->right, currSum, targetSum);
    seen[currSum]--;
}

int pathSum(TreeNode* root, int targetSum){
    seen[0] = 1;
    helper(root, 0, targetSum);
    return pathCount;
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
    int targetSum;
    cin>>targetSum;
    cout<<pathSum(root, targetSum)<<endl;
    return 0;
}