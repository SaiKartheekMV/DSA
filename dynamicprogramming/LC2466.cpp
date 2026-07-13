#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

/*int solve(int low, int high, int zero, int ones,
          int n, vector<int>& dp) {

    if(n > high){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ways = 0;

    if(n >= low && n <= high){
        ways = 1;
    }

    ways = (ways + solve(low, high, zero, ones,
                         n + zero, dp)) % MOD;

    ways = (ways + solve(low, high, zero, ones,
                         n + ones, dp)) % MOD;

    dp[n] = ways;

    return dp[n];
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int low, high, zero, ones;
    cin >> low >> high >> zero >> ones;

    vector<int> dp(high + 1, 0);
    for(int i = high;i>=0;i--){
        if(i >= low && i  <= high){
            dp[i] = 1;
        }

        if(i+zero <= high){
            dp[i] += dp[i+zero] % MOD;
        }
        if(i+ones <= high){
            dp[i] += dp[i+ones] % MOD;
        }
    }

   cout<<dp[0];

    return 0;
}