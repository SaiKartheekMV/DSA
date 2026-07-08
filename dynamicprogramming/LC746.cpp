#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost){
    int n = cost.size();
    vector<int>dp(n+1,-1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2;i<n;i++){
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    return min(dp[n-1], dp[n-2]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cout<<minCostClimbingStairs(cost)<<endl;
    return 0;
}