#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    
    int start = 0;
    int sum = 0;

    for (int end = 0;end<n;end++){
        sum += arr[end];

        while(sum > k){
            sum -= arr[start];
            start++;
        }
        
        if(sum==k){
            cout<<"yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}