#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(vector<int>& nums){
    int n = nums.size()-1;
    int slow = 2;
    for(int fast=2;fast<n;fast++){
        if(nums[fast]!=nums[slow-2]){
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return (slow+1);
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
    int ans = removeDuplicate(nums);
    cout<<ans<<endl;
    return 0;
}