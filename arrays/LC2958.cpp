#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int k, int n){
    int l = 0, ans = 0;
    unordered_map<int, int>freq;
    for(int r=0;r<n;r++){
        freq[nums[r]]++;
        while(freq[nums[r]] > k){
            freq[nums[l]]--;
            if(freq[nums[l]]==0){
                freq.erase(nums[l]);
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
    int n, k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    cout<<solve(nums, k, n)<<endl;
    return 0;
}