#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>color;
bool dfs(int node){
    color[node] = 1;

    for(int nei : graph[node]){
        if(color[nei]==1) return true;
        if(color[nei]==0){
            if(dfs(nei)) return true;
        }
    }
    color[node] = 2;
    return false;
}


bool canFinish(int n, vector<vector<int>>& prerequisites){
    graph.assign(n, {});
    color.assign(n, 0);

    for(auto&e : prerequisites){
        graph[e[1]].push_back(e[0]);
    }

    for(int i=0;i<n;i++){
        if(color[i]==0){
            if(dfs(i)) return false;
        }
    }

    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>prerequisites(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>prerequisites[i][j];
        }
    }
    bool ans = canFinish(n, prerequisites);
    if(ans){
        cout<<"Can finish"<<endl;
    }else{
        cout<<"Unable to finish"<<endl;
    }
    return 0;
}