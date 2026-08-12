#include<bits/stdc++.h>
using namespace std;

int atMost(vector<int>&nums, int k){
    int n = nums.size();
    int left = 0, count = 0, ans = 0;
    unordered_map<int,int>mp;
    for(int right=0;right<n;right++){
        mp[nums[right]]++;
        if(mp[nums[right]]==1){
            count++;
        }
        while(count > k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0){
                count--;
            }
            left++;
        }
        ans+= right-left+1;
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
    cout<<atMost(nums, k)-atMost(nums, k-1);
    return 0;
}