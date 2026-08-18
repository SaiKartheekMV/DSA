#include<bits/stdc++.h>
using namespace std;

bool feasible(string& s, string& p, vector<int>&removable, int X){
    vector<bool>removed(s.length(), false);
    for(int idx = 0; idx<X; idx++){
        removed[removable[idx]] = true;
    }
    int i=0, j=0;
    while(i < s.length() && j < p.length()){
        if(!removed[i] && s[i] == p[j]){
            j++;
        }
        i++;
    }

    return j == p.size();
}

int solve(string& s, string& p, vector<int>&removable, int n){
    int low = 0;
    int high = n;
    int ans = 0;
    while(low <= high){
        int mid =  low + (high - low) / 2;
        if(feasible(s, p, removable, mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid -1 ;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, p;
    int n;
    getline(cin, s);
    getline(cin, p);
    cin>>n;
    vector<int>removable(n);
    for(int i=0;i<n;i++){
        cin>>removable[i];
    }
    cout<<solve(s, p, removable, n)<<endl;
    return 0;
}