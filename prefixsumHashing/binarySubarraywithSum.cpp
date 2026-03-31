#include<bits/stdc++.h>
using namespace std;

int binarySubarray(vector<int>&nums, int goal){
    int n = nums.size();
    unordered_map<int, int>mp;
    mp[0]=1;
    int sum = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(mp.find(sum-goal)!=mp.end()){
            count+=mp[sum-goal];
        }
        mp[sum]++;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n,goal;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>goal;
    cout<<binarySubarray(nums, goal)<<endl;
    return 0;
}