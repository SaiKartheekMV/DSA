#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum = 0;
    int maxlen = 0;
    unordered_map<int, int> mp;
    for( int i = 0;i<n;i++){
        if(arr[i]==0){
            sum-=1;
        }else if(arr[i]==1){
            sum+=1;
        }

        if(sum == 0){
            maxlen = i+1;
        }
        if(mp.find(sum)!= mp.end()){
            maxlen = max(maxlen, i-mp[sum]);
        }
        else{
            mp[sum] = i;
        }
    }

    cout<<maxlen<<endl;
    return 0;
}