#include<bits/stdc++.h>
using namespace std;

string solve(string& s){
    int n = s.size();
    unordered_map<char, int>mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    priority_queue<pair<int, char>>pq;
    for(auto& m : mp){
        pq.push({m.second, m.first});
    }
    string ans;
    while(!pq.empty()){
        auto [freq, ch] = pq.top();
        pq.pop();

        while(freq--){
            ans+=ch;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    cout<<solve(s)<<endl;
    return 0;
}