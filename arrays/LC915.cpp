#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n){
    vector<int>prefixMax(n);
    vector<int>suffixMin(n);
    prefixMax[0] = nums[0];
    for(int i=1;i<n;i++){
        prefixMax[i] = max(prefixMax[i-1], nums[i]);
    }
    suffixMin[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMin[i] = min(suffixMin[i+1], nums[i]);
    }

    for(int i=0;i<n;i++){
        if(prefixMax[i] <= suffixMin[i+1]){
            return i+1;
        }
    }
    return 0;
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
    cout<<solve(nums, n)<<endl;
    return 0;
}