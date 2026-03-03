#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n-2;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int left = i+1;
        int right = n-1;
        while(left<right){
            int sum = nums[i]+nums[left]+nums[right];
            if(sum<0){
                left++;
            }else if(sum>0){
                right--;
            }else{
                ans.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1]) left++;
                while(left < right && nums[right] == nums[right+1]) right--;
            }
        }
    }
    return ans;
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
    vector<vector<int>>ans = threeSum(nums);
    for(auto &triplet : ans){
        cout << triplet[0] << " "
             << triplet[1] << " "
             << triplet[2] << "\n";
    }
    return 0;
}