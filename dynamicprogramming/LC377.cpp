#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin>>n>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>dp(target+1, 0);
    dp[0] = 1;
    for(int i=1;i<=target;i++){
        for(int num : nums){
            if(i - num < 0){
                continue;
            }
            dp[i]+=dp[i-num];
        }
    }
    cout<<dp[target]<<endl;
    return 0;
}