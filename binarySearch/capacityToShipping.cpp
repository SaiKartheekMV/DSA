#include<bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>weights, int d){
    int low  = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;

    while(low<=high){
        int mid = low + (high - low) / 2;
        int load = 0;
        int days = 1;

        for(int w : weights){
            if(load+w<=mid){
                load = load+w;
            }else{
                days++;
                load = w;
            }
        }
        
        if(days<=d){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>weights(n);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    int d;
    cin>>d;
    cout<<shipWithinDays(weights, d)<<endl;
    return 0;
}