#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,2,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(n == 1){
        cout<<"Array is sorted"<<endl;
    }else if(n==0){
        cout<<"Array is empty"<<endl;
    }
    for (int i=0; i<n;i++){
        if(arr[i]>arr[i+1]){
            cout<<"Array is not sorted"<<endl;
            break;
        }
    }
    return 0;
}