#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n==0){
        return 0;
    }else if(n==1){
        cout<<arr[0];
        return 0;
    }

    int k=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[k]=arr[i];
            k++;
        }
    }
    for(int i=k;i<n;i++){
        arr[i] = 0;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}