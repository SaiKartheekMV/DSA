#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;


void solve(vector<int>& nums, vector<int>& temp, vector<bool>&used){
    int prevElement = INT_MIN;
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return ;
    }

    for(int i=0;i<nums.size();i++){
        int currElement = nums[i];
        if(used[i]==false && currElement!=prevElement){
            temp.push_back(nums[i]);
            used[i] = true;
            solve(nums, temp,used);
            prevElement = currElement;
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
    sort(nums.begin(), nums.end());
    vector<int>temp;
    vector<bool>used(n, false);
    solve(nums, temp, used);
    for(auto& rows : ans){
        cout<<"[";
        for(auto& x : rows){
            cout<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}