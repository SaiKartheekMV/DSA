#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n){
    int currSum  = 0, ans = 0;
    int evenCount = 1;
    int oddCount = 0;
    for(int i=0;i<n;i++){
        currSum+=nums[i];
        if(currSum % 2 == 0){
            ans+=oddCount;
            evenCount++;
        }else{
            ans+=evenCount;
            oddCount++;
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
    cout<<solve(nums, n)<<endl;
    return 0;
}