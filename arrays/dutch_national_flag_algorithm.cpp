#include<bits/stdc++.h>
using namespace std;

vector<int>sortColors(vector<int>& colors){
    int n = colors.size();
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(colors[mid] == 0){
            swap(colors[low++],colors[mid++]);
        }else if(colors[mid]==1){
            mid++;
        }else{
            swap(colors[mid],colors[high--]);
        }
    }
    return colors;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>colors(n);
    for(int i=0;i<n;i++){
        cin>>colors[i];
    }
    sortColors(colors);
    for(auto p:colors){
        cout<<p<<" ";
    }
    return 0;
}