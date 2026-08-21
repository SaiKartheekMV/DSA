#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n){
    unordered_map<int, int>mp;
    int ans = n+1;
    for(int i = 0; i < n; i++){
        if(mp.find(nums[i])!=mp.end()){
            int previousIndex = mp[nums[i]];
            ans = min(ans, i-previousIndex+1);
        }
        mp[nums[i]] = i;
    }
    return ans == n+1 ? -1 : ans;
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
    cout<<solve(nums, n)<<endl;
    return 0;
}