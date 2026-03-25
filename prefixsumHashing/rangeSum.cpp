#include<bits/stdc++.h>
using namespace std;

int rangeSum(vector<int>&nums, int left, int right){
    int n = nums.size();
    vector<int>prefixSum(n+1, 0);
    for(int i=0;i<n;i++){
        prefixSum[i+1] = prefixSum[i] + nums[i];
    }

    return prefixSum[right+1] - prefixSum[left];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,left,right;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>left>>right;
    cout<<rangeSum(nums, left, right)<<endl;
    return 0;
}