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
    }
    int totalSum = n*(n+1)/2;
    int arrSum = 0;
    for(int i=0;i<n;i++){
        arrSum += arr[i];
    }
    int missingNum = totalSum - arrSum;
    cout<<missingNum<<endl;
    return 0;
}