#include<bits/stdc++.h>
using namespace std;

int reduceArray(vector<int>&arr){
    int n = arr.size();
    unordered_map<int, int>mp;
    for(int x : arr){
        mp[x]++;
    }
    vector<int>freq;
    for(auto& x : mp){
        freq.push_back(x.second);
    }
    sort(freq.begin(), freq.end(), greater<int>());
    int removed = 0, ans = 0;
    for(int x : freq){
        removed += x;
        ans+=1;
        if(removed >= n/2){
            return ans;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<reduceArray(arr)<<endl;
    return 0;
}