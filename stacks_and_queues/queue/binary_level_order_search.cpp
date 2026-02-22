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
        vector<vector<int>> levelOrder(TreeNode* root){
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
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    Solution obj;

    vector<vector<int>>result = obj.levelOrder(root);

    for(auto level: result){
        for(auto val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}