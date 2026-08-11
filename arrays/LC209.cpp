#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n, int target){
    int left = 0;
    int sum  = 0;
    int ans = INT_MAX;
    for(int right=0;right<n;right++){
        sum += nums[right];
        while(sum >= target){
            ans = min(ans, right-left+1);
            sum-=nums[left];
            left++;
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>target;
    cout<<solve(nums, n, target)<<endl;
    return 0;
}