#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    int leftMax = 0;
    int rightMax = 0;
    int maxWater = 0;
    int i=0, j = heights.size()-1;
    while(i<=j){
        leftMax =  max(leftMax, heights[i]);
        rightMax = max(rightMax, heights[j]);

        if(leftMax < rightMax){
            maxWater+= leftMax-heights[i];
            i++;
        }else{
            maxWater+=rightMax-heights[j];
            j--;
        }
    }
    cout<<maxWater<<endl;
    return 0;
}