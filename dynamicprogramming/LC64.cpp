#include<bits/stdc++.h>
using namespace std;

int solve(int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i-1 == m && j-1 == n){
                continue;
            }

            if(i+1 < m && j+1 < n){
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }

            if(i+1 < m){
                dp[i][j] = grid[i][j] + dp[i+1][j];
            }

            if(j+1 < n){
                dp[i][j] = grid[i][j] + dp[i][j+1];
            }
        }
    }
    return dp[0][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    vector<vector<int>>grid(m, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
    dp[m-1][n-1] = grid[m-1][n-1];
    cout<<solve(m, n, grid, dp)<<endl;
    return 0;
}