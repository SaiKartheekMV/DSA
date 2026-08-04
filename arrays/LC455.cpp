#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&g, vector<int>&s){
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int count = 0;
    int i=0;
    for(int j=0;j<s.size() && i < g.size();j++){
        if(s[j]>=g[i]){
            count++;
            i++;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    vector<int>g(m);
    vector<int>s(n);
    for(int i=0;i<m;i++){
        cin>>g[i];
    }
    for(int j=0;j<n;j++){
        cin>>s[j];
    }
    cout<<solve(g, s)<<endl;
    return 0;
}