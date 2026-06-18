#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, windSum;
    cin>>n;
    vector<int>nums(n);
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cin>>k;

    for(int i=0;i<k;i++){
        windSum+=nums[i];
    }

    for(int i=k;i<n;i++){
        windSum+=nums[i] - nums[i-k];
        maxSum = max(maxSum, windSum);
    }

    cout<<maxSum<<endl;
    return 0;
}