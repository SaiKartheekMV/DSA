#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution{
    public:
        vector<int>rightSideView(TreeNode* root){
            vector<int>ans;
            queue<TreeNode*>q;
            if(root==NULL) return ans;
            q.push(root);

            while(!q.empty()){
                int size = q.size();
                for(int i=0;i<size;i++){
                    auto node = q.front();
                    q.pop();

                    if(i==size-1){
                        ans.push_back(node->val);
                    }

                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            return ans;
        }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int>ans = obj.rightSideView(root);

    for(auto val : ans){
        cout<<val<<" ";
    }
    return 0;
}