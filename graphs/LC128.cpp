#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>&nums){
    int maxLen = 0;
    unordered_set<int>st;
    for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
    }


    for(int x : st){
        if(st.find(x-1)==st.end()){
            int len = 1;

            while(st.count(x+1)){
                x++;
                len++;
            }

            maxLen = max(len, maxLen);
        }
    }
    return maxLen;
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
    int ans = longestConsecutive(nums);
    cout<<ans<<endl;
    return 0;
}