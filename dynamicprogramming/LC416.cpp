#include<bits/stdc++.h>
using namespace std;

/*bool solve(vector<int>&nums, int index, int remainingSum, vector<bool>&dp){
    if(remainingSum==0){
        return true;
    }

    if(index==nums.size()){
        return false;
    }

    if(remainingSum < 0){
        return false;
    }

    if(dp[index][remainingSum]!=-1){
        return dp[index][remainingSum];
    }

    bool taken = solve(nums, index+1, remainingSum-nums[index]);
    bool skip = solve(nums, index+1, remainingSum);

    dp[index][remainingSum] = taken || skip;
    return dp[index][remainingSum];
}*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int target = 0;
    if(totalSum % 2 != 0){
        cout<<"false"<<endl;
        return 0;
    }else{
        target = totalSum / 2;
    }
    vector<vector<bool>> dp(
        n + 1,
        vector<bool>(target + 1, false)
    );
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=n-1;i>=0;i--){
        for(int remainingSum = 1;remainingSum<=target;remainingSum++){
            bool take = 0;
            if(remainingSum - nums[i] >=0){
                take = dp[i+1][remainingSum-nums[i]];
            }
            bool skip = dp[i+1][remainingSum];
            dp[i][remainingSum] = take || skip;
        }
    }
     if(dp[0][target]){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    return 0;
}