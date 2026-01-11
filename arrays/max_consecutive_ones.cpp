#include<bits/stdc++.h>
#include<math.h>
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
    int maxi = 0;
    int count = 0;
    for(int i=0;i<n;i++){
      if(arr[i]==1){
        count++;
      }else {
        maxi = max(maxi, count);
        count = 0;
      }
    }
    maxi =  max(maxi,count);
    cout<<maxi<<endl;
    return 0;
}