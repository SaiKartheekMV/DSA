#include<bits/stdc++.h>
using namespace std;

int sqrt(int x){
    int low = 1;
    int high = x;
    int ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid <= x / mid){
            ans = mid;
            low = mid + 1;
        }else if(mid > x / mid){
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    cout<<sqrt(x)<<endl;
    return 0;
}