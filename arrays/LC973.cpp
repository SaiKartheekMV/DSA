#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
vector<vector<int>>& solve(vector<vector<int>>&points, int n, int k){
    priority_queue<pair<int, pair<int, int>>>pq;
    int d = 0;
    for(auto&p : points){
        int x = p[0];
        int y = p[1];

        d = x*x + y * y;
        pq.push({d, {x, y}});

        if(pq.size() > k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        ans.push_back({pq.top().second.first, pq.top().second.second});
        pq.pop();
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;
    vector<vector<int>>points(n , vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>points[i][0]>>points[i][1];
    }
    cin>>k;
    solve(points, n, k);
    for(auto& x : ans){
        cout<<x[0]<<","<<x[1]<<endl;
    } 
    return 0;
}