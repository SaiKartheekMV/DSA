#include<bits/stdc++.h>
using namespace std;

int findDivisor(vector<int>&nums, int threshold){
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;

    while(low<=high){
        int mid = low + (high - low) / 2;
        int sum = 0;

        for(int n : nums){
            sum += (n+mid - 1) / mid;
        }

        if(sum<=threshold){
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
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int threshold;
    cin>>threshold;
    cout<<findDivisor(nums, threshold)<<endl;
    return 0;
}