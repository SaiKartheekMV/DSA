#include<bits/stdc++.h>
using namespace std;

int kokoBanana(vector<int>& piles, int h){
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    long long totalHours = 0;
    int ans = 0;
    while(low<=high){
        int mid  = low + (high - low) / 2;

        for(int p : piles){
            totalHours += (p + mid - 1) / mid;
        }

        if(totalHours<=h){
            ans = mid;
            high = mid - 1;
        }else{
            low =  mid + 1;
        }
        totalHours = 0;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,h;
    cin>>n;
    vector<int>piles(n);
    for(int i=0;i<n;i++){
        cin>>piles[i];
    }
    cin>>h;
    cout<<kokoBanana(piles, h)<<endl;
    return 0;
}