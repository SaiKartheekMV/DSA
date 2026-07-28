#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    for(int i=n-1;i>=0;i--){
        for(int prev = i-1;prev>=-1;prev--){
            int take = 0;
            if(prev==-1 || nums[i]>nums[prev]){
                take = 1+dp[i+1][i+1];
            }
            int skip = dp[i+1][prev+1];
            dp[i][prev+1] = max(take, skip);
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}