#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n){
    priority_queue<int>pq;
    for(int x : nums){
        pq.push(x);
    }

    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if(x != y){
            pq.push(x-y);
        }
    }

    return pq.empty() ? 0 : pq.top();
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