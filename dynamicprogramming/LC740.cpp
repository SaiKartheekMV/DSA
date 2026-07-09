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
    int maxValue = *max_element(nums.begin(), nums.end());
    vector<int>points(maxValue+1, 0);
    for(int x : nums){
        points[x]+=x;
    } 
    int next1 = 0;
    int next2 = 0;
    for(int i=maxValue;i>=0;i--){
        int curr = max(points[i]+next2, next1);
        next2 = next1;
        next1 = curr;
    }
    cout<<next1<<endl;
    return 0;
}