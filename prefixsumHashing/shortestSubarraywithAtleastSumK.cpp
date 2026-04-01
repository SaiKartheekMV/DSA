#include<bits/stdc++.h>
using namespace std;

int shortestSubarrayAtleastKsum(vector<int>&nums, int k){
    int n = nums.size();
    vector<long long>prefix(n+1, 0);
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]+nums[i-1];
    }
    
    deque<int>dq;
    int ans = INT_MAX;

        for(int j = 0; j <= n; j++){
            while(!dq.empty() && prefix[j] - prefix[dq.front()] >= k){
                ans = min(ans, j - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[j] <= prefix[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
        }

    return ans == INT_MAX ? -1 : ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n,k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    cout<<shortestSubarrayAtleastKsum(nums, k)<<endl;
    return 0;
}