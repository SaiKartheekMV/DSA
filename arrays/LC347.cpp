#include<bits/stdc++.h>
using namespace std;


vector<int> topKelements(vector<int>&nums, int k){
    unordered_map<int, int>mp;
    for(int x : nums){
        mp[x]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>heap;

    for(auto& x : mp){
        heap.push({x.second, x.first});

        if(heap.size() > k){
            heap.pop();
        }
    }

    vector<int>ans;
    for(int i=0;i<k;i++){
        ans.push_back(heap.top().second);
        heap.pop();
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    vector<int>ans = topKelements(nums, k);
    for(int x : ans){
        cout<<x<<" ";
    }
    return 0;
}