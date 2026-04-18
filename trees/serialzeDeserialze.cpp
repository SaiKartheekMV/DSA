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

queue<string>q;

string serialze(TreeNode* root){
    if(root==NULL) return "#";
    string s = to_string(root->val);
    s = s + "," + serialze(root->left) + "," + serialze(root->right);
    return s;
}

TreeNode* helper(queue<string>&q){
    string s = q.front();
    q.pop();
    if(s=="#") return NULL;
    TreeNode* root = new TreeNode(stoi(s));
    root->left = helper(q);
    root->right = helper(q);
    return root;
}


TreeNode* deserialze(string data){
    stringstream ss(data);
    string token;
    while(getline(ss, token, ',')){
        q.push(token);
    }
    TreeNode* root = helper(q);
    return root;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Build a sample tree
    //       1
    //      / \
    //     2   3
    //        / \
    //       4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize
    string serialized = serialze(root);
    cout << "Serialized: " << serialized << endl;

    // Deserialize
    TreeNode* newRoot = deserialze(serialized);
    cout << "Deserialized root: " << newRoot->val << endl;
    cout << "Left: " << newRoot->left->val << endl;
    cout << "Right: " << newRoot->right->val << endl;
    return 0;
}
