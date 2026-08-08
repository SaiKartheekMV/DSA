#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&gas, vector<int>&cost, int n){
    int currFuel = 0;
    int totalFuel = 0;
    int start = 0;
    for(int i=0;i<n;i++){
        totalFuel += gas[i]-cost[i];
        currFuel += gas[i]-cost[i];
        if(currFuel < 0){
            start = i+1;
            currFuel = 0;
        }
    }
    return (totalFuel < 0) ? -1 : start;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>gas(n);
    vector<int>cost(n);
    for(int i=0;i<n;i++){
        cin>>gas[i];
    }
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    cout<<solve(gas, cost, n);
    return 0;
}