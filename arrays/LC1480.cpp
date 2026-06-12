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
    for(int i=1;i<n;i++){
        nums[i] += nums[i-1];
    }

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}