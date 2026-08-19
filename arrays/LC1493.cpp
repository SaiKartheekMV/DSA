#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&nums, int n){
    int l = 0, ans = 0, zeros = 0;
    for(int r=0;r<n;r++){
        if(nums[r]==0) zeros ++;
        while(zeros > 1){
            if(nums[l]==0){
                zeros--;
            }
            l++;
        }

        ans = max(ans, r-l);
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
    cout<<solve(nums, n)<<endl;
    return 0;
}