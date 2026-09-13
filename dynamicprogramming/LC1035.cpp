#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n1, n2;
    cin>>n1>>n2;
    vector<int>nums1(n1);
    vector<int>nums2(n2);
    for(int i=0;i<n1;i++){
        cin>>nums1[i];
    }
    for(int j=0;j<n2;j++){
        cin>>nums2[j];
    }
    vector<vector<int>>dp(n1+1, vector<int>(n2+1));
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            dp[n1][j] = 0;
            dp[i][n2] = 0;
        }
    }
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            if(nums1[i]==nums2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
}