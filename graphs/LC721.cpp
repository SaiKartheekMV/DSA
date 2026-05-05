#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int>parents, rank_;
    int components;

    DSU(int n): parents(n), rank_(n, 0), components(n){
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
        if(rank_[py]>rank_[px]) swap(px, py);
        parents[py] = px;
        if(rank_[px]==rank_[py]) rank_[px]--;
        components--;
        return true;
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }
};


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    DSU dsu(10001);
    unordered_map<string, int> emailToIndex;
    unordered_map<string, string> emailToName;
    int id = 0;

    for(auto& acc : accounts){
        string& name = acc[0];
        for(int i = 1; i < acc.size(); i++){
            string& email = acc[i];
            if(emailToIndex.find(email) == emailToIndex.end()){
                emailToIndex[email] = id++;
            }
            emailToName[email] = name;

            dsu.unite(emailToIndex[acc[1]], emailToIndex[email]);
        }
    }

    unordered_map<int, vector<string>> groups;
    for(auto& entry : emailToIndex){
        const string& email = entry.first;
        int idx = entry.second;
        int root = dsu.find(idx);
        groups[root].push_back(email);
    }

    vector<vector<string>>result;
    for(auto& p : groups){
        int root = p.first;
        vector<string>& emails = p.second;
        sort(emails.begin(), emails.end());
        emails.insert(emails.begin(), emailToName[emails[0]]);
        result.push_back(emails);
    }
    return result;
}