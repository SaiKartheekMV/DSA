#include<bits/stdc++.h>
using namespace std;

int MinimumSizeSubarraySum(vector<int>&nums, int k){
    int n = nums.size();
    int left = 0;
    int sum = 0, ans = INT_MAX;
    for(int right = 0;right < n;right++){
        sum+=nums[right];
        while(sum>=k){
            ans = min(ans, right-left+1);
            sum-=nums[left];
            left++;
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    cout<<MinimumSizeSubarraySum(nums, k)<<endl;
    return 0;
}