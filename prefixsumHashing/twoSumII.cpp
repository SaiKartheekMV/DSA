#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int>mp;
    int complement = 0;
    for(int i=0;i<nums.size();i++){
        complement = target - nums[i];
        if(mp.find(complement)!=mp.end()){
            return {mp[complement], i+1};
        }
        mp[nums[i]] = i+1;
    }
    return {};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin>>n;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    cin>>target;

    vector<int> result = twoSum(nums, target);

    if(result.size() == 2){
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }
    return 0;
}