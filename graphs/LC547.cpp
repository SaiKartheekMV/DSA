#include<bits/stdc++.h>
using namespace std;

class DSU {
    public:
    vector<int>parents, rank_;
    int components;

    DSU(int n) : parents(n), rank_(n,0), components(n){
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int x){
        if(parents[x]!=x){
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    bool unite(int i, int j){
        int px = find(i), py = find(j);
        if(px==py) return false;
        if(rank_[px] == rank_[py]) swap(px, py);
        parents[py] = px;
        if(rank_[px]==rank_[py]) rank_[px]++;
        components--;
        return true;
    }

    bool connected(int i, int j){
        return find(i) == find(j);
    }
};


int findCircleNum(vector<vector<int>>& isConnected){
    DSU dsu(isConnected.size());
    for(int i=0;i<isConnected.size();i++){
        for(int j=0;j<isConnected[0].size();j++){
            if(isConnected[i][j]==1){
                dsu.unite(i,j);
            }
        }
    }
    return dsu.components;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>isConnected(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>isConnected[i][j];
        }
    }
    int ans = findCircleNum(isConnected);
    cout<<ans<<endl;
    return 0;
}