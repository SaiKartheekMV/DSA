#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parents, ranks, size;
    int components;

    DSU(int n) : parents(n), ranks(n, 0), size(n, 1), components(n) {
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    bool unite(int i, int j) {
        int px = find(i);
        int py = find(j);

        if (px == py) return false;

        // Union by rank
        if (ranks[py] > ranks[px]) {
            swap(px, py);
        }

        parents[py] = px;
        size[px] += size[py];

        if (ranks[px] == ranks[py]) {
            ranks[px]++;
        }

        components--;
        return true;
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

int malwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    int n = graph.size();

    DSU dsu(n);

    // Build connected components
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] == 1) {
                dsu.unite(i, j);
            }
        }
    }

    // Count infected nodes in each component
    unordered_map<int, int> malwareCnt;

    for (int node : initial) {
        malwareCnt[dsu.find(node)]++;
    }

    sort(initial.begin(), initial.end());

    int result = initial[0];
    int maxSaved = 0;

    for (int node : initial) {
        int root = dsu.find(node);

        // Only one malware node in this component
        if (malwareCnt[root] == 1) {

            // Save the largest component
            if (dsu.size[root] > maxSaved) {
                maxSaved = dsu.size[root];
                result = node;
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> initial(m);

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Input infected nodes
    for (int i = 0; i < m; i++) {
        cin >> initial[i];
    }

    int ans = malwareSpread(graph, initial);

    cout << ans << endl;

    return 0;
}