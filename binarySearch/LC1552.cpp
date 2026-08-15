#include<bits/stdc++.h>
using namespace std;


bool feasible(vector<int>&position, int m, int gap, int n){
    int lastPlaced = position[0];
    int count = 1;
    for(int i=1;i<n;i++){
        if(position[i]-lastPlaced >= gap){
            count++;
            lastPlaced = position[i];
        }
    }
    return (count >= m);
}


int solve(vector<int>&position, int m, int n){
    sort(position.begin(), position.end());
    int low = 1;
    int high = position.back() - position.front();
    int ans = low;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(feasible(position, m, mid, n)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n;
    vector<int>positions(n);
    for(int i=0;i<n;i++){
        cin>>positions[i];
    }
    cin>>m;
    cout<<solve(positions, m, n)<<endl;
    return 0;
}