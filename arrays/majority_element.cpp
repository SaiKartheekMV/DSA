#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int candidate = 0;
    int count = 0;
    
    for(int i=0;i<n;i++){
        if(count == 0){
            candidate = arr[i];
            count = 1;
        }else if(candidate == arr[i]){
            count++;
        }else{
            count--;
        }
    }
    cout<<candidate<<endl;
    return 0;
}