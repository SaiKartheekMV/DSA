#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long>dp(n+1, 0);
    dp[0] = 0;
    if(n==0){
        cout<<dp[0]<<endl;
        return 0;
    }
    dp[1] = 1;
    if(n==1){
        cout<<dp[1]<<endl;
        return 0;
    }
    dp[2] = 1;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<dp[n]<<endl;
    return 0;
}