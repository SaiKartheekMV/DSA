#include<bits/stdc++.h>
using namespace std;

int solve(int m, int n, vector<vector<int>>&mat, vector<vector<int>>&dp){
    int ans = 0;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(mat[i][j]==0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = 1+min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]));
            }
            ans += dp[i][j];
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    vector<vector<int>>matrix(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    cout<<solve(m, n, matrix, dp)<<endl;
    return 0;
}