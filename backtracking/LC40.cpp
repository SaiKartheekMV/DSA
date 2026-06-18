#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;
int prevElement;

void solve(int idx, vector<int>&temp, vector<int>&nums, int target){
    if(target==0){
        ans.push_back(temp);
        return ;
    }

    if(target<0){
        return ;
    }

    for(int i=idx;i<nums.size();i++){
        int currElement = nums[i];
        if(currElement!=prevElement){
            temp.push_back(nums[i]);
            solve(i+1, temp, nums, target-nums[i]);
            prevElement = currElement;
            temp.pop_back();
        }
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
    solve(0, temp, nums, target);
    for(auto& rows : ans){
        cout<<"[";
        for(auto& x : rows){
            cout<<x<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}