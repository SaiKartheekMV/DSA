#include<bits/stdc++.h>
using namespace std;


class DSU{
    public:
        vector<int>parent, rank_;
        int components;
        DSU(int n) : parent(n), rank_(n,0), components(n){
            iota(parent.begin(), parent.end(),0);
        }

        int find(int x){
            if(parent[x]!=x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y){
            int px = find(x), py = find(y);
            if(px==py) return false;
            if(rank_[px] < rank_[py]) swap(px, py);
            parent[py] = px;
            if(rank_[px]==rank_[py]) rank_[px]++;
            components--;
            return true;
        }

        bool connected(int x, int y){
            return find(x) == find(y);
        }
};


bool validPath(int n, vector<vector<int>>&edges, int source, int destination){
    DSU dsu(n);
    for(int i=0;i<edges.size();i++){
        dsu.unite(edges[i][0], edges[i][1]);
    }
    return dsu.connected(source, destination);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, source, destination;
    cin>>n;
    vector<vector<int>>edges(n, vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    cin>>source>>destination;
    bool ans = validPath(n, edges, source, destination);
    if(ans){
        cout<<"Path exist";
    }else{
        cout<<"Path Does not exist";
    }
    return 0;
}