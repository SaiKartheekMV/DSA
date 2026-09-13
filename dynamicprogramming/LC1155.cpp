#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, target;
    cin>>n>>k>>target;
    vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
    dp[0][0] = 1;
    const int MOD = 1e9 + 7;
    for(int d=1;d<=n;d++){
        for(int t=1;t<=target;t++){
            for(int x=1;x<=k;x++){
                if(t-x >= 0){
                    dp[d][t] = (dp[d][t] + dp[d-1][t-x]) % MOD;
                }
            }
        }
    }
    cout<<dp[n][target]<<endl;
    return 0;
}