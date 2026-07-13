#include<bits/stdc++.h>
using namespace std;

/*int solve(vector<int>&coins, int amount , int index, vector<vector<int>>&dp){
    if(amount == 0){
        return 1;
    }

    if(index==coins.size()){
        return 0;
    }

    if(amount < 0){
        return 0;
    }

    if(dp[index][amount]!= -1){
        return dp[index][amount];
    }

    int take = solve(coins, amount-coins[index], index, dp);
    int skip = solve(coins, amount, index+1, dp);

    dp[index][amount] = take+skip;
    return dp[index][amount];
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,amount;
    cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<vector<unsigned int>>dp(n+1, vector<unsigned int>(amount+1, 0));
    for(int index=0;index<=n;index++){
        dp[index][0] = 1;
    }

    for(int index = n-1;index>=0;index--){
        for(int currAmount = 0;currAmount<=amount;currAmount++){
            unsigned int take = 0;
            if(currAmount-coins[index] >=0 ){
                take = dp[index][currAmount-coins[index]];
            }
            unsigned int skip = dp[index+1][currAmount];
            dp[index][currAmount] = take+skip;
        }
    }
    cout<<dp[0][amount]<<endl;
    return 0;
}