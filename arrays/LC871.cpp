#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&nums, int target, int start, int n){
    int stops = 0, i = 0;
    int curr = start;
    priority_queue<int>pq;
    while(curr < target){
        while( i < nums.size() && nums[i][0] <= curr){
            pq.push(nums[i][1]);
            i++;
        }

        if(pq.empty()){
            return -1;
        }

        curr+=pq.top();
        pq.pop();
        stops++;
    }
    return stops;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target, start;
    cin>>n;
    vector<vector<int>>nums(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>nums[i][0]>>nums[i][1];
    }
    cin>>start>>target;
    cout<<solve(nums, target, start, n)<<endl;
    return 0;
}