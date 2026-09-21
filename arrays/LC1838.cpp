#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n, int k){
    int l = 0, ans = 0;
    long long sum = 0;
    for(int r=0;r<n;r++){
        sum += nums[r];
        while(1LL* nums[r] * (r-l+1) - sum > k){
            sum-=nums[l];
            l++;
        }
        ans = max(ans, r-l+1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    cout<<solve(nums, n, k)<<endl;
    return 0;
}