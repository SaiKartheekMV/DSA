#include<bits/stdc++.h>
using namespace std;

vector<bool>arithmeticSubarrays(vector<int>& arr, vector<int>& l, vector<int>& r){
    vector<bool>ans;
    vector<int>temp;
    for(int i=0;i<l.size();i++){
        for(int j=l[i];j<=r[i];j++){
            temp.push_back(arr[j]);
        }
        sort(temp.begin(), temp.end());
        if (temp.size() < 2) {
            ans.push_back(true);
            temp.clear();
            continue;
        }
        int firstDiff = temp[1]-temp[0];
        bool ok = true;
        for(int k=1;k<temp.size();k++){
            if(temp[k]-temp[k-1]!=firstDiff){
                ok = false;
                break;
            }
        }
        ans.push_back(ok);
        temp.clear();
    }
    return ans; 
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,z;
    cin>>x>>y>>z;
    vector<int>arr(x);
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
    vector<int>l(y);
    vector<int>r(z);
    for(int i=0;i<y;i++){
        cin>>l[i];
    }
    for(int i=0;i<z;i++){
        cin>>r[i];
    }
    vector<bool>ans = arithmeticSubarrays(arr, l, r);
    for(auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}