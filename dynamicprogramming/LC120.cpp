#include<bits/stdc++.h>
using namespace std;

int solve(int m, vector<vector<int>>&triangle, vector<vector<int>>&dp){
    for(int i=m-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            if(i==m-1){
                continue;
            }

            if(i+1 < m && j+1< m){
                dp[i][j] = triangle[i][j]+min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
    }
    return dp[0][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>m;
    vector<vector<int>>triangle(m);
    for(int i=0;i<m;i++){
        triangle[i].resize(i+1);
        for(int j=i;j<=i;j++){
            cin>>triangle[i][j];
        }
    }
    vector<vector<int>>dp(m, vector<int>(m, INT_MAX));
    for(int j=0;j<m;j++){
        dp[m-1][j] = triangle[m-1][j];
    }
    cout<<solve(m, triangle, dp);
    return 0;
}