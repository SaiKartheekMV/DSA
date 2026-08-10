#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&h, int bricks, int ladders){
    int n = h.size();
    priority_queue<int, vector<int>, greater<int>>q;
    for(int i=0;i<n-1;i++){
       int diff = h[i+1]-h[i];
       if(diff <= 0){
        continue;
       }
       q.push(diff);
       if((int)q.size() > ladders){
        bricks-=q.top();
        q.pop();
       }
       if(bricks< 0 ) {
        return i;
       }
    }
    return n-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, bricks, ladders;
    cin>>n;
    vector<int>h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    cin>>bricks>>ladders;
    cout<<solve(h, bricks, ladders)<<endl;
    return 0;
}