#include<bits/stdc++.h>
using namespace std;

/*int solve(vector<int>&nums, int index, int currSum, int target, vector<vector<int>>&dp, int total){
    if(index == nums.size()){
        return (currSum == target);
    }

    if(dp[index][currSum+total]!= -1){
        return dp[index][currSum+total];
    }

    int positive = solve(nums, index+1, currSum+nums[index], target, dp, total);
    int negative = solve(nums, index+1, currSum-nums[index], target, dp , total);
    dp[index][currSum+total] = positive + negative;
    return dp[index][currSum+total];
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin>>n>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int totalSum  = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>>dp(
        n+1,
        vector<int>(2*totalSum+1, 0)
    );

    if(target >= -totalSum && target <= totalSum){
        dp[n][target+totalSum] = 1;
    }
    for(int index = n-1;index>=0;index--){
        for(int currSum = -totalSum;currSum<=totalSum;currSum++){
            int positive = 0;
            int negative = 0;
            if(currSum+nums[index]<=totalSum){
                positive = dp[index+1][currSum+nums[index]+totalSum];
            }

            if(currSum-nums[index]>=-totalSum){
                negative = dp[index+1][currSum-nums[index]+totalSum];
            }

            dp[index][currSum+totalSum] = positive+negative;
        }
    }
    cout<<dp[0][totalSum]<<endl;
    return 0;
}