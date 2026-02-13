#include<bits/stdc++.h>
using namespace std;

int longestSubarray0and1(vector<int>&nums){
    int sum = 0;
    int maxi = 0;
    unordered_map<int, int>mp;
    mp[0] = -1;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] == 0){
            sum+= -1;
        }else{
            sum+= 1;
        }

        if(mp.find(sum)!=mp.end()){
            maxi = max(maxi, i-mp[sum]);
        }else{
            mp[sum] = i;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans = longestSubarray0and1(nums);
    cout<<ans<<endl;
    return 0;
}