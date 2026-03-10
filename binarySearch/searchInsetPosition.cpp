#include<bits/stdc++.h>
using namespace std;

int searchInsertPos(vector<int>&nums, int target){
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>target;
    int ans = searchInsertPos(nums, target);
    cout<<ans<<endl;
    return 0;
}