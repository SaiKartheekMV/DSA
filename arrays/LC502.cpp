#include<bits/stdc++.h>
using namespace std;

int solve(int k, int w, vector<int>&profits, vector<int>&capitals){
    int n = profits.size();
    vector<vector<int>>pairs;
    for(int i=0;i<n;i++){
        pairs.push_back({capitals[i], profits[i]});
    }
    sort(pairs.begin(), pairs.end(), [](vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    });

    int j=0;
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        while(j<n && pairs[j][0]<=w){
            pq.push(pairs[j][1]);
            j++;
        }
        if(!pq.empty()){
            w+=pq.top();
            pq.pop();
        }
    }
    return w;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>profits(n);
    vector<int>capitals(n);
    for(int i=0;i<n;i++){
        cin>>profits[i];
    }
    for(int i=0;i<n;i++){
        cin>>capitals[i];
    }
    int k,w;
    cin>>k>>w;
    cout<<solve(k,w,profits,capitals);
    return 0;
}