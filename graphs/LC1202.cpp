#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int> parents, ranks;
    int components;

    DSU(int n) : parents(n), ranks(n, 0), components(n){
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int x){
        if(parents[x] != x){
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    bool unite(int i, int j){
        int px = find(i), py = find(j);

        if(px == py) return false;

        if(ranks[py] > ranks[px]){
            swap(px, py);
        }

        parents[py] = px;

        if(ranks[px] == ranks[py]){
            ranks[px]++;
        }

        components--;
        return true;
    }

    bool connected(int i, int j){
        return find(i) == find(j);
    }
};

string smallestString(string s, vector<vector<int>>& pairs){

    DSU dsu(s.length());

    for(auto& p : pairs){
        dsu.unite(p[0], p[1]);
    }

    unordered_map<int, vector<int>> groups;

    for(int i = 0; i < s.length(); i++){
        groups[dsu.find(i)].push_back(i);
    }

    string result = s;

    for(auto& [root, indices] : groups){

        vector<int> idx = indices;
        vector<char> chars;

        sort(idx.begin(), idx.end());

        for(int i : idx){
            chars.push_back(s[i]);
        }

        sort(chars.begin(), chars.end());

        for(int i = 0; i < idx.size(); i++){
            result[idx[i]] = chars[i];
        }
    }

    return result;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int m;

    cin >> m;
    cin >> s;

    vector<vector<int>> pairs;

    for(int i = 0; i < m; i++){

        int u, v;
        cin >> u >> v;

        pairs.push_back({u, v});
    }

    string result = smallestString(s, pairs);

    cout << result << endl;

    return 0;
}