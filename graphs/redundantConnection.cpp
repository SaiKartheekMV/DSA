#include<bits/stdc++.h>
using namespace std;

bool dfs(int src, int target, unordered_set<int>&visited, vector<vector<int>>& adj){
    if (src == target) return true;
    visited.insert(src);
    for(auto& neighbor : adj[src]){
        if(!visited.count(neighbor)){
            if(dfs(neighbor, target, visited, adj)) return true;
        }
    }
    return false;
}



vector<int> findReduntantConnections(vector<vector<int>>& edges){
    vector<vector<int>>adj(edges.size()+1);

    for(auto& edge : edges){
        unordered_set<int>visited;
        if(dfs(edge[0], edge[1], visited, adj)) return edge;
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);            
    }
    return  {};
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m;
    cin >> m;
    
    vector<vector<int>> edges(m, vector<int>(2));
    for(int i = 0; i < m; i++){
        cin >> edges[i][0] >> edges[i][1];
    }
    
    vector<int> result = findReduntantConnections(edges);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
    
    return 0;
}