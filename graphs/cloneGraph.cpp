#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbours;

    Node(int _val) {
        val = _val;
    }
};

// DFS clone
Node* dfs(Node* node, unordered_map<Node*, Node*>& mp) {
    if (node == NULL) return NULL;

    if (mp.find(node) != mp.end()) {
        return mp[node];
    }

    Node* clone = new Node(node->val);
    mp[node] = clone;

    for (auto neighbor : node->neighbours) {
        clone->neighbours.push_back(dfs(neighbor, mp));
    }

    return clone;
}

// Clone Graph
Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> mp;
    return dfs(node, mp);
}

// Print Graph (DFS)
void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node || visited[node]) return;

    visited[node] = true;

    cout << "Node " << node->val << " -> ";
    for (auto n : node->neighbours) {
        cout << n->val << " ";
    }
    cout << endl;

    for (auto n : node->neighbours) {
        printGraph(n, visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // Connect graph
    n1->neighbours = {n2, n4};
    n2->neighbours = {n1, n3};
    n3->neighbours = {n2, n4};
    n4->neighbours = {n1, n3};

    cout << "Original Graph:\n";
    unordered_map<Node*, bool> visited1;
    printGraph(n1, visited1);

    Node* cloned = cloneGraph(n1);

    cout << "\nCloned Graph:\n";
    unordered_map<Node*, bool> visited2;
    printGraph(cloned, visited2);

    return 0;
}