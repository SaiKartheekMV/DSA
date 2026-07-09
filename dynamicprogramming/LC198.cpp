#include<bits/stdc++.h>
using namespace std;

int func(vector<int>&nums, vector<int>&dp){
    int n = nums.size();
    for(int i=n-1;i>=0;i--){
        dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
    }
    return dp[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>dp(n+2, -1);
    dp[n] = 0;
    dp[n+1] = 0;
    cout<<func(nums, dp)<<endl;
    return 0;
}