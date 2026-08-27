#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int k, int n){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(nums[i]);

        if(pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    cout<<solve(nums, k, n)<<endl;
    return 0;
}