#include<bits/stdc++.h>
using namespace std;

vector<int>& solve(vector<int>&nums, int n, vector<int>&visible){
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        int count = 0;
        while(!st.empty() && nums[st.top()] < nums[i]){
            count++;
            st.pop();
        }

        if(!st.empty()){
            count++;
        }

        visible[i] = count;
        st.push(i);
    }
    return visible;
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
    vector<int>visible(n, 0);
    vector<int>res = solve(nums, n, visible);
    for(int x : res){
        cout<<x<<" ";
    }
    return 0;
}