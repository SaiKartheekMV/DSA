#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;

void solve(int idx, vector<int>&temp, vector<int>&nums){
    if(idx==nums.size()){
        ans.push_back(temp);
        return ;
    }

    temp.push_back(nums[idx]);
    solve(idx+1, temp, nums);
    temp.pop_back();
    solve(idx+1, temp, nums);
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
        for(auto& x : rows){
            cout<<x<<" ";
        }
        cout<<"]"<<"\n";
    }
    return 0;
}