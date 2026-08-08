#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>>&points){
    int count = 1;
    sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    });
    int lastElement = points[0][1];
    for(int i=1;i<n;i++){
        if(points[i][0]<=lastElement){
            lastElement = min(lastElement, points[i][1]);
        }else{
            lastElement = points[i][1];
            count++;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>points(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>points[i][0]>>points[i][1];
    }
    cout<<solve(n, points);
    return 0;
}