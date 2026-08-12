#include<bits/stdc++.h>
using namespace std;


bool solve(vector<int>&nums, int k){
    unordered_map<int, int>mp;
    mp[0] = -1;
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        int remainder = (sum % k + k) % k;
        if(mp.find(remainder)!=mp.end()){
            if(i-mp[remainder]>= 2){
                return true;
            }
        }else{
            mp[remainder] = i;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>k;
    if(solve(nums, k)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}