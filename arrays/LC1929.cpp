#include<bits/stdc++.h>
using namespace std;

void concatenation(vector<int>& nums){
    int n = nums.size();
    vector<int>ans(2*n);
    for(int i=0;i<n;i++){
        ans[i] = nums[i];
        ans[i+n] = nums[i];
    }

    for(int x : ans){
        cout<<x<<" ";
    }
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
    concatenation(nums);
    return 0;
}