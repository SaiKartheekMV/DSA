#include<iostream>
using namespace std;

int main(){
    int n;
    int seclarge = -1;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest =arr[i];
        }
    }

    for (int i=0;i<n;i++){
        if(arr[i]!=largest && arr[i]>seclarge){
            seclarge = arr[i];
        }
    }

    cout << seclarge << endl;
    return 0;
}