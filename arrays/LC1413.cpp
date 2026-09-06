#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n){
    int prefixSum = 0;
    int minPrefix = 0;
    for(int x : nums){
        prefixSum += x;
        minPrefix = min(minPrefix, prefixSum);
    }
    return 1-minPrefix;
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