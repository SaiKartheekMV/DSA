#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&people, int limit, int n){
    sort(people.begin(), people.end());
    int ans = 0;
    int i=0;
    int j = n-1;
    while(i<=j){
        if(people[i]+people[j]<=limit){
            i++;
        }
        j--;
        ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,limit;
    cin>>n;
    vector<int>people(n);
    for(int i=0;i<n;i++){
        cin>>people[i];
    }
    cin>>limit;
    cout<<solve(people, limit, n)<<endl;
    return 0;
}