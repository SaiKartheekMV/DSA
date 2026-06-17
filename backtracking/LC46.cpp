#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;

void permute(vector<int>&temp, vector<int>&nums, vector<bool>&used){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return ;
    }

    for(int i=0;i<nums.size();i++){
        if(used[i]==false){
            temp.push_back(nums[i]);
            used[i] = true;
            permute(temp, nums, used);
            temp.pop_back();
            used[i] = false;
        }
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
    vector<bool>used(n, false);
    permute(temp, nums, used);
    for(auto& rows : ans){
        cout<<"[";
        for(auto& x : rows){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}