#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&fruits, int n){
    unordered_map<int, int>mp;
    int l=0, ans=0;
    for(int r=0;r<n;r++){
        mp[fruits[r]]++;
        while(mp.size() > 2){
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0){
                mp.erase(fruits[l]);
            }
            l++;
        }
        ans = max(ans, r-l+1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>fruits(n);
    for(int i=0;i<n;i++){
        cin>>fruits[i];
    }
    cout<<solve(fruits, n)<<endl;
    return 0;
}