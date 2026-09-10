#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>questions(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>questions[i][0]>>questions[i][1];
    }
    vector<long long>dp(n+1, 0);
    dp[n] = 0;
    for(int i=n-1;i>=0;i--){
        int skip = dp[i+1];
        int next = i+questions[i][1] + 1;
        int solve = questions[i][0];
        if(next < n){
            solve+=dp[next];
        }
        dp[i] = max(solve, skip);
    }
    cout<<dp[0]<<endl;
    return 0;
}