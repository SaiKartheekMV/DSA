#include<bits/stdc++.h>
using namespace std;

bool solve(int n){
    vector<int>dp(n+1, 0);
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        for(int x = 1; x<i; x++){
            if(i % x == 0 && dp[i-x] == 0){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n] == 0 ? false : true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(solve(n)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}