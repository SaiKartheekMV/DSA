#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, totalSum, sum;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    totalSum = accumulate(nums.begin(), nums.end(), 0);
    sum = 0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum-nums[i]==totalSum-sum){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}