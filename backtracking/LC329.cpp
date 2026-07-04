#include<bits/stdc++.h>
using namespace std;

int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    
    int best = 1;

    if(r+1 < matrix.size() && matrix[r+1][c] > matrix[r][c]){
        best = max(best, 1+dfs(r+1, c, matrix, dp));
    }

    if(r-1 >= 0 && matrix[r-1][c] > matrix[r][c]){
        best = max(best, 1+dfs(r-1, c, matrix, dp));
    }

    if(c-1 >= 0 && matrix[r][c-1] > matrix[r][c]){
        best = max(best, 1+dfs(r, c-1, matrix, dp));
    }

    if(c+1 < matrix[0].size() && matrix[r][c+1] > matrix[r][c]){
        best = max(best, 1+dfs(r, c+1, matrix, dp));
    }

    return dp[r][c] = best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int ans = 0;
    cin>>n>>m;
    vector<vector<int>>matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>dp(n, vector<int>(m, -1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans, dfs(i, j, matrix, dp));
        }
    }
    cout<<ans<<endl;
    return 0;
}