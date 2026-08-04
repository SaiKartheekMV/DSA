#include<bits/stdc++.h>
using namespace std;;

int solve(vector<vector<int>>&intervals){
    sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    });
    int count = 0;
    int lastElement = intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]>=lastElement){
            lastElement = intervals[i][1];
        }else{
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
    vector<vector<int>>intervals(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    cout<<solve(intervals);
    return 0;
}