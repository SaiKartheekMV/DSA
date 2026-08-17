#include<bits/stdc++.h>
using namespace std;

bool feasible(vector<int>&price, int n, int k, int X){
    int lastPrice = price[0];
    int count = 1;
    for(int i=1;i<n;i++){
        if(price[i]-lastPrice >= X){
            count++;
            lastPrice = price[i];
        }
    }

    return (count >= k);
}

int solve(vector<int>&price, int n, int k){
    sort(price.begin(), price.end());
    int low = 0;
    int high = price.back() -price.front();
    int ans = high;
    while(low <= high){
        int mid =  low + (high - low) / 2;
        if(feasible(price, n, k, mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;
    vector<int>price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    cin>>k;
    cout<<solve(price, n, k)<<endl;
    return 0;
}