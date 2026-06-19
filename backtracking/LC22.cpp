#include<bits/stdc++.h>
using namespace std;

vector<string>ans;

void solve(string s, int open, int close, int n){
    if(open == n && close == n){
        ans.push_back(s);
        return ;
    }

    if(open < n){
        s.push_back('(');
        solve(s, open+1, close, n);
        s.pop_back();
    }

    if(close < open){
        s.push_back(')');
        solve(s, open, close+1, n);
        s.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s = "";
    solve(s, 0, 0, n);
    for(auto& x : ans){
        cout<<x<<endl;
    }
    return 0;
}