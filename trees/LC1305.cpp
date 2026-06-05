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

void pushElement(vector<int>&ans, TreeNode* root){
    if(root==NULL){
        return ;
    }

    pushElement(ans, root->left);
    ans.push_back(root->val);
    pushElement(ans, root->right);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
    vector<int>ans;
    pushElement(ans, root1);
    pushElement(ans, root2);
    sort(ans.begin(), ans.end());
    return ans;
}

TreeNode* buildTree(vector<int>& nodes){
    if(nodes.empty() || nodes[0] == -1){
        return NULL;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < nodes.size()){
        TreeNode* curr = q.front();
        q.pop();

        if(i < nodes.size() && nodes[i] != -1){
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if(i < nodes.size() && nodes[i] != -1){
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n1;
    cin >> n1;

    vector<int> tree1(n1);
    for(int i = 0; i < n1; i++){
        cin >> tree1[i];
    }

    int n2;
    cin >> n2;

    vector<int> tree2(n2);
    for(int i = 0; i < n2; i++){
        cin >> tree2[i];
    }

    TreeNode* root1 = buildTree(tree1);
    TreeNode* root2 = buildTree(tree2);

    vector<int> ans = getAllElements(root1, root2);

    for(int x : ans){
        cout << x << " ";
    }

    cout << '\n';

    return 0;
}