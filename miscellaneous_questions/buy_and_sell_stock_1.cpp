#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int prices[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

    int pf = 0;
    int mini = prices[0];

    for(int i=1;i<n;i++){
        int cost = prices[i] - mini;
        pf = max(pf, cost);
        mini = min(mini, prices[i]);
    }

    cout<<pf<<endl;
    return 0;
}