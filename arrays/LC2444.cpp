#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n, int mink, int maxk){
    int lastmink = -1, lastmaxk = -1, lastInvalid = -1;
    int ans = 0;
    for(int i=0;i<n;i++){

        if(nums[i] < mink || nums[i] > maxk){
            lastInvalid = i;
        }

        if(nums[i]==mink){
            lastmink = i;
        }

        if(nums[i]==maxk){
            lastmaxk = i;
        }

        int latestValid = min(lastmink, lastmaxk);
        if(latestValid > lastInvalid){
            ans += latestValid - lastInvalid;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, minK, maxK;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>minK>>maxK;
    cout<<solve(nums, n, minK, maxK)<<endl;
    return 0;
}