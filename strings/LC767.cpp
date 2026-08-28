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
    int maxFreq = pq.top().first;
    if(maxFreq > (n+1)/2){
        return "";
    }
    string ans;
    int prevFreq = 0;
    char prevChar = '#';
    while(!pq.empty()){
        auto[freq, ch] = pq.top();
        pq.pop();
        ans+=ch;
        freq--;

        if(prevFreq > 0){
            pq.push({prevFreq, prevChar});
        }

        prevFreq = freq;
        prevChar = ch;
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