#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n, int p){
    int totalSum = 0;
    for(int x : nums){
        totalSum += x;
    }
    int r = totalSum % p;
    if(r==0){
        return 0;
    }
    int ans = n;
    int curr = 0;
    unordered_map<int, int>mp;
    mp[0] = -1;
    for(int i=0;i<n;i++){
        curr = (curr + nums[i]) % p;
        int need = (curr - r + p) % p;
        if(mp.find(need) != mp.end()){
            ans = min(ans, i-mp[need]);
        }

        mp[curr] = i;
    }
    return ans == n ? -1 : ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>p;
    cout<<solve(nums, n, p)<<endl;
    return 0;
}