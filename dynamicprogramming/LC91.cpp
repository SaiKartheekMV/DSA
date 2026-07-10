#include<bits/stdc++.h>
using namespace std;

int solve(string &s, vector<int>&dp){
    int n = s.length();
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            dp[i] = 0;
            continue;
        }

        int ways = 0;
        ways += dp[i+1];

        if(i+1<n){
            int num = (s[i]-'0')* 10  + (s[i+1]-'0');
            if(10 <= num && num <= 26){
                ways += dp[i+2];
            }
        }
        dp[i] = ways;
    }
    return dp[0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    int n = s.length();
    vector<int>dp(n+2, 0);
    dp[n+1] = 0;
    dp[n] = 1;
    cout<<solve(s, dp);
    return 0;
}