#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>&nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int ans1 = -1, ans2 = -1;

    while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            ans1 = mid;
            high = mid - 1;
        }else if(nums[mid]<target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }


    low = 0;
    high = nums.size()-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            ans2 = mid;
            low = mid + 1;
        }else if(nums[mid] > target){
            high = mid - 1;
        }else{
            low = mid+1;
        }
    }

    return {ans1, ans2};
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
    vector<int>ans(2);
    int target;
    cin>>target;
    ans = searchRange(nums, target);
    for(auto p:ans){
        cout<<p<<" ";
    }
    return 0;
}