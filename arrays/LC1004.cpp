#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int k, int n){
    int ans = 0;
    int count = 0;
    int l = 0;
    for(int r=0;r<n;r++){
        if(nums[r]==0){
            count++;
        }
        while(count > k){
            if(nums[l]==0){
                count--;
            }
            l++;
        }
        ans = max(ans, r-l+1);
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
    cout<<solve(nums, k, n)<<endl;
    return 0;
}