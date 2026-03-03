#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>fourSum(vector<int>& nums, int target){
    vector<vector<int>>ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0;i<n-3;i++){
        if(i>0 &&  nums[i] == nums[i-1]) continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && nums[j]==nums[j-1]) continue;

            int left = j+1;
            int right = n-1;

            while(left<right){
                long long sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];

                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                    left++;
                    right--;

                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                }else if(sum<target){
                    left++;
                }else{
                    right--;
                }
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
    int target;
    cin>>target;
    vector<vector<int>>ans = fourSum(nums, target);
     for(auto &vec : ans){
        for(int x : vec){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}