#include<bits/stdc++.h>
using namespace std;

int rainWater(vector<int>&heights){
    int left = 0;
    int right = heights.size()-1;
    int leftMax = 0;
    int rightMax = 0;
    int ans = 0;

    while(left<right){
        if(heights[left]<heights[right]){
            if(heights[left]>=leftMax){
                leftMax = heights[left];
            }else{
                ans+=leftMax-heights[left];
            }
            left++;
        }else{
            if(heights[right]>=rightMax){
                rightMax = heights[right];
            }else{
                ans+=rightMax-heights[right];
            }
            right--;
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    int ans = rainWater(heights);
    cout<<ans<<endl;
    return 0;
}

