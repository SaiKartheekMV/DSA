#include<bits/stdc++.h>
using namespace std;

int rotatedArray(vector<int>&nums, int target){
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[low] <= nums[mid]){
            if(nums[low]<=target && target<nums[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if(nums[mid]<target && target<=nums[high]){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
    }
    return -1;
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
    int target;
    cin>>target;
    cout<<rotatedArray(nums, target)<<endl;
    return 0;
}