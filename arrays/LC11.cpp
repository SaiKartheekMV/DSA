#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int i = 0, j = nums.size()-1;
    int maxArea = 0;
    while(i<=j){
        int minHeight = min(nums[i], nums[j]);
        int width = j-i;
        int currArea = minHeight*width;
        maxArea = max(currArea, maxArea);
        if(nums[i]<nums[j]){
            i++;
        }else{
            j--;
        }
    }
    cout<<maxArea<<endl;
    return 0;
}