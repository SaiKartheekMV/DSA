#include<bits/stdc++.h>
using namespace std;

int solve(int m ,int n, vector<vector<int>>&obstacleGrid, vector<vector<long long>>&dp){
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(obstacleGrid[i][j]==1){
                continue;
            }

            if(i+1 < m){
                dp[i][j] += dp[i+1][j];
            }

            if(j+1 < n){
                dp[i][j] += dp[i][j+1];
            }
        }
    }
    return (int) dp[0][0];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    vector<vector<int>>obstacleGrid(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>obstacleGrid[i][j];
        }
    }
    if(obstacleGrid[m-1][n-1]==1){
        return 0;
    }
    vector<vector<long long>>dp(m, vector<long long>(n, 0));
    dp[m-1][n-1] = 1;
    cout<<solve(m, n, obstacleGrid, dp)<<endl;
    return 0;
}