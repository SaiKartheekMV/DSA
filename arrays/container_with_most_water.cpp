#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height){
    int i=0,j=height.size()-1;
    int maxArea = 0;
    while(i<j){
        int width = j-i;
        int minHeight = min(height[i],height[j]);
        int currArea = minHeight*width;

        maxArea = max(maxArea, currArea);
        if(height[i]<height[j]){
            i++;
        }else{
            j--;
        }
    }
    return maxArea;
}

int main(){
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int area = maxArea(height);
    cout<<area<<endl;
    return 0;
}