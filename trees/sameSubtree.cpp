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

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    return (p->val == q->val) &&  isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot){
    if(subRoot == NULL) return true;
    if(root == NULL) return false;

    return isSameTree(root, subRoot) 
        || isSubtree(root->left, subRoot) 
        || isSubtree(root->right, subRoot);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->right = new TreeNode(4);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(6);
    root1->right->left = new TreeNode(7);
    TreeNode* subRoot = new TreeNode(3);
    subRoot->left = new TreeNode(7);
    subRoot->right = new TreeNode(4);
    if(isSubtree(root1, subRoot)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}