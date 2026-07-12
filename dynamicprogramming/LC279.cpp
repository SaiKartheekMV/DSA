#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            int square = j*j;
            if(dp[i-square]!=INT_MAX){
                dp[i] = min(dp[i], 1+dp[i-square]);
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}