#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& houses, int start, int end){
    int next1 = 0;
    int next2 = 0;
    for(int i=start;i>=end;i--){
        int curr = max(houses[i]+next2, next1);
        next2 = next1;
        next1 = curr;
    }
    return max(next1, next2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>houses(n);
    for(int i=0;i<n;i++){
        cin>>houses[i];
    }
    int ans1 = solve(houses, n-1, 1);
    int ans2 = solve(houses, n-2, 0);
    cout<<max(ans1, ans2)<<endl;
    return 0;
}