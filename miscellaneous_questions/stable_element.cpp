#include<bits/stdc++.h>
using namespace std;

int firstStableElement(vector<int>& nums){
    int n = nums.size();
    if(n < 3) return -1;

    long long sum = 0;
    for(int x : nums) sum += x;

    long long left = nums[0];

    for(int i = 1; i <= n - 2; i++){
        long long right = sum - left - nums[i];

        if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1] && left > right){
            return i;
        }
        left += nums[i];
    }
    return -1;
}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = firstStableElement(arr);
    cout<<ans<<endl;
    return 0;
}