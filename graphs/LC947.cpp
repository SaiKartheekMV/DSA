#include<bits/stdc++.h>
using namespace std;

class DSU{
public:

    vector<int> parents, rank_;
    
    DSU(int n){
        parents.resize(n);
        rank_.resize(n,0);

        iota(parents.begin(), parents.end(), 0);
    }

    int find(int x){

        if(parents[x] != x){
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    bool unite(int i, int j){

        int px = find(i);
        int py = find(j);

        if(px == py) return false;

        if(rank_[py] > rank_[px]){
            swap(px,py);
        }

        parents[py] = px;

        if(rank_[px] == rank_[py]){
            rank_[px]++;
        }

        return true;
    }
};

int noOfStones(vector<vector<int>>& stones){

    DSU dsu(20002);

    for(auto &stone : stones){

        int row = stone[0];
        int col = stone[1] + 10001;

        dsu.unite(row,col);
    }

    unordered_set<int> components;

    for(auto &stone : stones){

        components.insert(dsu.find(stone[0]));
        components.insert(dsu.find(stone[1] + 10001));
    }

    return stones.size() - components.size();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> stones(n, vector<int>(2));

    for(int i=0;i<n;i++){
        cin >> stones[i][0] >> stones[i][1];
    }

    int ans = noOfStones(stones);

    cout << ans << endl;

    return 0;
}