#include<bits/stdc++.h>
using namespace std;
vector<int>res;
vector<int>& solve(vector<int>&nums, int n, int k){
    for(int i=0;i<n;i++){
        while(!res.empty() && nums[i] < res.back() && res.size() + n - i - 1 >= k){
            res.pop_back();
        }
        res.push_back(nums[i]);
        while(res.size()  > k){
            res.pop_back();
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
       cin>> nums[i];
    }
    cin>>k;
    vector<int>result = solve(nums, n, k);
    for(int x : result){
        cout<<x<<" ";
    }
    return 0;
}