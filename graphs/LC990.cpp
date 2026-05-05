#include<bits/stdc++.h>
using namespace std;


class DSU{
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
        if(px == py) return false;
        if(rank_[py] > rank_[px]) swap(px , py);
        parents[py] = px;
        if(rank_[px]==rank_[py]) rank_[px]++;
        components--;
        return true;
    }

    bool connected(int i, int j){
        return find(i) == find(j);
    }
};


bool equationsPossible(vector<string>& equations){
    DSU dsu(26);
    for(auto& eq : equations){
        if(eq[1]=='='){
            dsu.unite(eq[0]-'a', eq[3]-'a');
        }
    }

    for(auto& eq : equations){
        if(eq[1]=='!'){
            if(dsu.connected(eq[0]-'a', eq[0]-'a')) return false;
        }
    }
    
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string>equations(n);
    for(int i=0;i<n;i++){
        cin>>equations[i];
    }
    bool ans = equationsPossible(equations);
    if(ans){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}

