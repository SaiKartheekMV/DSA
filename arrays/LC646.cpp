#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>>&pairs){
    sort(pairs.begin(), pairs.end(), [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    });
    int count  = 1;
    int lastElement = pairs[0][1];
    for(int i=1;i<n;i++){
        if(lastElement < pairs[i][0]){
            count++;
            lastElement = pairs[i][0];
        }
    }
    return count++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>pairs(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>pairs[i][0]>>pairs[i][1];
    }
    cout<<solve(n, pairs);
    return 0;
}