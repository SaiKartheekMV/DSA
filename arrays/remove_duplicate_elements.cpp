#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k=1;
    int i=0;
    if (n==0){
        return 0;
    }
    if(n==1){
        cout<<arr<<endl;
        return 0;
    }

    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            k+=1;
            i++;
            arr[i]=arr[j];
        }
    }
    cout<<k<<endl;
    return 0;
}