#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int maxDepth = -1;
int sum = 0;

void dfs(TreeNode* node, int depth){
    if(node==nullptr){
        return ;
    }

    if(node->left == nullptr && node->right == nullptr){
        if(depth > maxDepth){
            maxDepth = depth;
            sum = node->val;
        }else if(depth == maxDepth){
            sum+=node->val;
        }
        return ;
    }

    dfs(node->left, depth+1);
    dfs(node->right, depth+1);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    dfs(root, 0);
    cout<<sum<<endl;
    return 0;
}