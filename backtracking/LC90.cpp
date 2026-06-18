#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;

void solve(int idx, vector<int>&temp, vector<int>&nums){
    ans.push_back(temp);

    for(int i=idx;i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1]){
            continue;
        }
        temp.push_back(nums[i]);
        solve(i+1, temp, nums);
        temp.pop_back();
    }
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

    vector<int>temp;
    solve(0, temp, nums);
    for(auto& rows : ans){
        cout<<"[";
        for(auto& x  : rows){
            cout<<x<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}