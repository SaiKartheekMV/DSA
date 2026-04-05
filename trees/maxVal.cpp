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

vector<int> maxVal(TreeNode* root){
    vector<int>ans;
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        int maxVal = INT_MIN;
        for(int i=0;i<size;i++){
            auto node = q.front();
            q.pop();
            maxVal = max(maxVal, node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(maxVal);
    }
    return ans;
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
    vector<int> ans  = maxVal(root);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}