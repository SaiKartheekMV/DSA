#include<bits/stdc++.h>
using namespace std;

int splitArrayLargestSum(vector<int>&nums, int k){
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int ans = high;

    while(low<=high){
        int mid = low + (high - low) / 2;
        int subarrayCnt = 1;
        int subarraySum = 0;

        for(int n:nums){
            if(subarraySum+n<=mid){
                subarraySum += n;
            }else{
                subarrayCnt++;
                subarraySum = n;
            }
        }

        if(subarrayCnt <= k){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
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
    cout<<splitArrayLargestSum(nums, k)<<endl;
    return 0;
}