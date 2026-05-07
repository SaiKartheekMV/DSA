#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int>parents, ranks;
    int components;

    DSU(int n) : parents(n), ranks(n,0), components(n){
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
        if(ranks[py]>ranks[px]) swap(px, py);
        parents[py] = px;
        if(ranks[px]==ranks[py]) ranks[px]++;
        components--;
        return true;
    }

    bool connected(int i, int j){
        return find(i)==find(j);
    }
};


int makeConnected(int n, vector<vector<int>>& connections){
    DSU dsu(n);
    int spare = 0;

    for(auto& c : connections){
        if(!dsu.unite(c[0], c[1])) spare++;
    }

    int needed = dsu.components - 1;
    if(spare<needed) return -1;
    return needed;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<int>>connections;
    for(int i=0;i<m;i++){
        int v, u;
        cin>>v>>u;
        connections.push_back({v,u});
    }
    int ans = makeConnected(n, connections);
    cout<<ans<<endl;
    return 0;
}