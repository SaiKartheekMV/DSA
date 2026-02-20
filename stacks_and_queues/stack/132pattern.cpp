#include<bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int> &nums){
    stack<int>st;
    int n = nums.size();
    int second = INT_MIN;

    for(int i=n-1;i>=0;i--){

        if(nums[i]<second){
            return true;
        }

        while(!st.empty() && nums[i]>st.top()){
            second = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    bool ans = find132pattern(nums);
    if(ans){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}