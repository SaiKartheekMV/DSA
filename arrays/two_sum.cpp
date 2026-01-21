#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum;
    cin>>sum;
    
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]==sum){
            cout<<"Yes"<<endl;
            return 0;
        }else if(arr[i]+arr[j]<sum){
            i++;
        }else {
            j--;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
