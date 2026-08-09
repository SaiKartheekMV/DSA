#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&courses, int n){
    sort(courses.begin(), courses.end(), [](vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    });
    int total_days = 0;
    int count = 0;
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        if(total_days+courses[i][0]<=courses[i][1]){
            total_days+=courses[i][0];
            count++;
            pq.push(courses[i][0]);
        }else if(!pq.empty()){
            if(courses[i][0]<pq.top()){
                total_days -= pq.top();
                pq.pop();
                total_days += courses[i][0];
                pq.push(courses[i][0]);
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>>courses(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>courses[i][0]>>courses[i][1];
    }
    cout<<solve(courses,n)<<endl;
    return 0;
}