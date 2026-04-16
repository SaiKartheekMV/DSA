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

int k1;
int ans;

void helper(TreeNode* root){
    if(root==NULL) return ;
    helper(root->left);
    k1--;
    if(k1==0){
        ans = root->val;
        return;
    }
    helper(root->right);
}


int kthSmallest(TreeNode* root, int k){
    k1 = k;
    helper(root);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k;
    cin>>k;
    cout<<kthSmallest(root, k)<<endl;
    return 0;
}