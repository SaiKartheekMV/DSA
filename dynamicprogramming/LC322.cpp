#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&coins, vector<int>&dp, int amount){
    for(int i=1;i<=amount;i++){
        for(int coin : coins){
            if(i-coin <  0){
                continue;
            }

            if(dp[i-coin]!=INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,amount;
    cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>dp(amount+1, INT_MAX);
    dp[0] = 0;
    cout<<solve(coins, dp, amount);
    return 0;
}