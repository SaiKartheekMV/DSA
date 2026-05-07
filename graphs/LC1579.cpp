#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int>parents, ranks;
    int components;

    DSU(int n) : parents(n), components(n), ranks(n,0){
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
        if(ranks[py] > ranks[px]) swap(px, py);
        parents[py] = px;
        if(ranks[px]==ranks[py]) ranks[px]++;
        components--;
        return true;
    }

    bool connected(int i, int j){
        return find(i) == find(j);
    }
};

int edgeRemove(int n, vector<vector<int>>& edges){
    DSU dsua(n+1);
    DSU dsub(n+1);
    int removed = 0;
    for(auto&e : edges){
        if(e[0]==3){
            bool a = dsua.unite(e[1], e[2]);
            bool b = dsub.unite(e[1], e[2]);
            if(!a && !b) removed++;
        }
    }

    for(auto& e : edges){
        if(e[0]==1){
            bool a = dsua.unite(e[1], e[2]);
            if(!a) removed++;
        }
    }

    for(auto&e : edges){
        if(e[0]==2){
            bool b = dsub.unite(e[1], e[2]);
            if(!b) removed++;
        }
    }

    if(dsua.components != 2 || dsub.components != 2) return -1;
    return removed;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u , v, w;
        cin>>u>>v>>w;
        edges.push_back({u,v, w});
    }

    int ans = edgeRemove(n, edges);
    cout<<ans<<endl;
    return 0;
}