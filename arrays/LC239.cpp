#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<int>result;
    deque<int>dq;

    for(int i=0;i<n;i++){
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(dq.front() < i-k+1) dq.pop_front();
        if(i >= k-1) result.push_back(nums[dq.front()]);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}