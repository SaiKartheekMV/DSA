#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums){
    vector<int>arr(nums.size(), -1);
    stack<int>st;

    for(int i=0;i<2*nums.size();i++){
        int idx = i % nums.size();
        while(!st.empty() && nums[st.top()]<nums[idx]){
            int prev = st.top();
            st.pop();
            arr[prev] = nums[idx];
        }
        if(i<nums.size()){
            st.push(idx);
        }
    }

    return arr;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans = nextGreaterElement(nums);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}