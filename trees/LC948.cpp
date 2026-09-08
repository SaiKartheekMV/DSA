#include<bits/stdc++.h>
using namespace std;

int cameras = 0;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


int dfs(TreeNode* root){
    if(root == NULL){
        return 2;
    }

    int left = dfs(root->left);
    int right = dfs(root->right);

    if(left == 0 || right == 0){
        cameras++;
        return 1;
    }

    if(left == 1 || right == 1){
        return 2;
    }

    return 0;
}

int binaryTreeCameras(TreeNode* root){
    if(dfs(root) == 0){
        cameras++;
    }
    return cameras;
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
    cout<<binaryTreeCameras(root)<<endl;
    return 0;
}