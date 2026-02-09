#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    for(int i=1;i<n-2;i++){
        if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
            cnt+=1;
            ans.push_back(arr[i]);
        }
    }

    cout<<cnt<<endl;
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}