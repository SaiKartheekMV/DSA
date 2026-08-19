#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n){
    int currSum = 0, ans = 0, l = 0;
    unordered_set<int>st;
    for(int r=0;r<n;r++){
        while(st.count(nums[r])){
            st.erase(nums[l]);
            currSum-=nums[l];
            l++;
        }
        st.insert(nums[r]);
        currSum+=nums[r];
        ans = max(ans, currSum);
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