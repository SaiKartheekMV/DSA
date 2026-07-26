#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>>&dp, vector<vector<int>>&matrix){
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==n-1){
                continue;
            }

            int a = INT_MAX, b = INT_MAX, c = INT_MAX;
            if(j-1 >= 0){
                a = dp[i+1][j-1];
            }
            b = dp[i+1][j];
            if(j+1 < n){
                c = dp[i+1][j+1];
            }

            int mini = min(a, min(b,c));
            dp[i][j] = matrix[i][j] + mini;
        }
    }
    int ans = INT_MAX;
    for(int j=0;j<n;j++){
        ans = min(ans, dp[0][j]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>matrix(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>dp(n, vector<int>(n, INT_MAX));

    for(int j=0;j<n;j++){
        dp[n-1][j] = matrix[n-1][j];
    }
    cout<<solve(n, dp, matrix)<<endl;
    return 0;
}