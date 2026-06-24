#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
    int n = intervals.size();
    int i = 0;
    vector<vector<int>>ans;

    while(i< n && intervals[i][1] < newInterval[0]){
        ans.push_back(intervals[i]);
        i++;
    }

    while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    ans.push_back(newInterval);

    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>intervals(n,vector<int>(2));
    vector<int>newInterval(2);
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }

    cin>>newInterval[0]>>newInterval[1];

    vector<vector<int>>ans = insertInterval(intervals, newInterval);
    for(auto& x : ans){
        cout<<x[0]<<x[1]<<endl;
    }
    return 0;
}