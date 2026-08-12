#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int k){
    unordered_map<int, int>mp;
    mp[0] = 1;
    int ans = 0, currSum = 0;
    for(int x : nums){
        currSum+=x;
        int diff = currSum - k;
        ans += mp[diff];
        mp[currSum]++;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    cout<<solve(nums, k)<<endl;
    return 0;
}