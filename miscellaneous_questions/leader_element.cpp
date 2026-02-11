#include<bits/stdc++.h>
using namespace std;

vector<int> leaderElement(vector<int>& arr){
    int n = arr.size();
    int maxRight = INT_MIN;
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>=maxRight){
            ans.push_back(arr[i]);
            maxRight = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans = leaderElement(arr);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}