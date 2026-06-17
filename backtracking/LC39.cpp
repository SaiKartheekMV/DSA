#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;

void solve(int idx, vector<int>&temp, int target, vector<int>&nums){
    if(target==0){
        ans.push_back(temp);
        return ;
    }

    if(target<0){
        return ;
    }

    for(int i=idx; i<nums.size();i++){
        temp.push_back(nums[i]);
        solve(i, temp, target-nums[i], nums);
        temp.pop_back();
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>target;
    vector<int>temp;
    solve(0, temp, target, nums);
    for(auto& rows : ans){
        cout<<"[";
        for(auto& x : rows){
            cout<<x<<" ";
        }
        cout<<"]"<<"\n";
    }
    return 0;
}