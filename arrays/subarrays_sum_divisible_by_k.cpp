#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int sum = 0;
    int rem = 0;
    int count = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for ( int i=0;i<n;i++){
        sum += arr[i];
        rem = (sum % k + k) % k;

        if(mp.find(rem)!=mp.end()){
            count+= mp[rem];
        }

        mp[rem]++;

    }

    cout<<count<<endl;
    return 0;
}