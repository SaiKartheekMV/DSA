#include<bits/stdc++.h>
using namespace std;

int solve(string& s){
    int n = s.size();
    const int MOD = 1e9 + 7;
    vector<long long>last(26, 0);
    long long total = 1;
    for(char c : s){
        long long oldTotal = total;
        total = (2*total - last[c-'a'] + MOD) % MOD;
        last[c-'a'] = oldTotal;
    }

    return (total - 1 + MOD) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    cout<<solve(s)<<endl;
    return 0;
}