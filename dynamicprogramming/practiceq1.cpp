#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int>&dp){
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>dp(n+1, -1);
    dp[0] = 0;
    if(n>=1){
        dp[1] = 1;
    }
    cout<<fibonacci(n, dp)<<endl;
    return 0;
}