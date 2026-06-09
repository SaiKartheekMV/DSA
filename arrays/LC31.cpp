#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            ind = i;
            break;
        }
    }

    if(ind!=-1){
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i], nums[ind]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}