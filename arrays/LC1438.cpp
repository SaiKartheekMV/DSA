#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n, int limit){
    int l = 0, ans = 0;
    deque<int>maxDq;
    deque<int>minDq;
    for(int r=0;r<n;r++){
        while(!maxDq.empty() && nums[maxDq.back()] <= nums[r]){
            maxDq.pop_back();
        }
        maxDq.push_back(r);
        while(!minDq.empty() && nums[minDq.back()] >= nums[r]){
            minDq.pop_back();
        }
        minDq.push_back(r);

        while(nums[maxDq.front()] - nums[minDq.front()] > limit){
            l++;
            if(maxDq.front() < l){
                maxDq.pop_front();
            }
            if(minDq.front() < l){
                minDq.pop_front();
            }
        }
        ans = max(ans, r-l+1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, limit;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>limit;
    cout<<solve(nums, n, limit)<<endl;
    return 0;
}