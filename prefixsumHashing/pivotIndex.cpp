#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>&nums){
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum-nums[i] == totalSum-sum){
            return i;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<pivotIndex(nums)<<endl;
    return 0;
}