#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>ans;

void solve(int i, vector<int>&temp, int n, int k){
    if(temp.size()==k){
        ans.push_back(temp);
        return ;
    }

    for(int idx=i;idx<=n;idx++){
        temp.push_back(idx);
        solve(idx+1, temp, n, k);
        temp.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    vector<int>temp;
    solve(1, temp, n, k);
    for(auto& rows : ans){
        cout<<"[";
        for(auto& x : rows){
            cout<<x<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}