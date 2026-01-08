#include<iostream>
using namespace std;

void Reverse(int arr[], int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void RotateArrayLeft(int arr[], int n, int d){
    Reverse(arr, 0, d-1);
    Reverse(arr, d, n-1);
    Reverse(arr, 0, n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cin>>d;
    d = d % n;
    RotateArrayLeft(arr,n,d);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}