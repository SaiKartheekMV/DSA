#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int>&nums1, vector<int>&nums2){
    int n = nums2.size();
    vector<int>arr(n, -1);
    stack<int>st;

    for(int i=0;i<n;i++){
        while(!st.empty() && nums2[st.top()]<nums2[i]){
            int idx = st.top();
            st.pop();
            arr[idx] = nums2[i];
        }
        st.push(i);
    }

    unordered_map<int,int>mp;

    for(int i=0;i<n;i++){
        mp[nums2[i]] = arr[i];
    }

    vector<int>ans;
    for( int x:nums1){
        ans.push_back(mp[x]);
    }
    return ans;
}


int main(){
    int n1, n2;
    cin>>n1>>n2;
    vector<int>nums1(n1);
    vector<int>nums2(n2);
    for(int i=0;i<n1;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<n2;i++){
        cin>>nums2[i];
    }

    vector<int>ans;
    ans = nextGreater(nums1,nums2);
    for(int x:ans){
        cout<<x<<endl;
    }
    return 0;
}