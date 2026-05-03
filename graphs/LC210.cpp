#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> color;

bool dfs(int node, vector<int>& result){
    color[node] = 1;

    for(int nei : graph[node]){
        if(color[nei] == 1) return true;
        if(color[nei] == 0){
            if(dfs(nei, result)) return true;
        }
    }

    color[node] = 2;
    result.push_back(node);
    return false;
}

vector<int> findOrder(int n, vector<vector<int>>& prerequisites){
    vector<int> result;
    graph.assign(n, {});
    color.assign(n, 0);

    for(auto &e : prerequisites){
        graph[e[1]].push_back(e[0]);
    }

    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            if(dfs(i, result)) return {};
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));

    for(int i = 0; i < m; i++){
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<int> ans = findOrder(n, prerequisites);

    if(ans.empty()){
        cout << "Cycle detected, no valid order\n";
    } else {
        for(int x : ans){
            cout << x << " ";
        }
    }

    return 0;
}