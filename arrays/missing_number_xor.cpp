#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int xorAll = 0;
    for(int i=0;i<=n;i++){
        xorAll^=i;
    }

    int xorArr = 0;
    for(int i=0;i<n;i++){
        xorArr ^=arr[i];
    }

    int missingNum = xorAll ^ xorArr;
    cout<<missingNum<<endl;
    return 0;
}