#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums, int n){
    vector<int>left(n), right(n);
    stack<int>st;

    const long long MOD = 1e9 +7;

    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }

        if(st.empty()){
            left[i] = -1;
        }else{
            left[i] = st.top();
        }

        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }

        if(st.empty()){
            right[i] = n;
        }else{
            right[i] = st.top();
        }

        st.push(i);
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        int leftChoice = left[i] - i;
        int rightChoice = i - right[i];

        long long contribution = nums[i] * leftChoice * rightChoice;

        ans = (ans + contribution) % MOD;
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
    cout<<solve(nums, n)<<endl;
    return 0;
}