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

vector<vector<int>>levelOrderTraversal(TreeNode* root){
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    if(root==NULL) return ans;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            auto node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}

