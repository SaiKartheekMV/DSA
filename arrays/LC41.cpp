#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&nums){
    int n = nums.size();
    for(int i=0;i<n;i++){
        while(nums[i]>= 1 && nums[i]<= n && nums[i]!=nums[nums[i]-1] ){
            swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i=0;i<n;i++){
        if(nums[i]!= i+1){
            return i+1;
        }
    }

    return n+1;
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
    cout<<missingNumber(nums)<<endl;
    return 0;
}