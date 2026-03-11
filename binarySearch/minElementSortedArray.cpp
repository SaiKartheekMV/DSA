#include<bits/stdc++.h>
using namespace std;

int minimumElement(vector<int>&nums){
    int low = 0;
    int high = nums.size()-1;

    while(low<high){
        if(nums[low]<=nums[high]){
            return nums[low];
        }

        int mid = low + (high - low) / 2;

        if(nums[mid]>nums[high]){
            low = mid + 1;
        }else if(nums[mid]<=nums[high]){
            high = mid;
        }
    }
    return nums[low];
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
    cout<<minimumElement(nums)<<endl;
    return 0;
}