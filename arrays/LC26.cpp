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
    sort(nums.begin(), nums.end());
    int i = 0;
    for(int j=1;j<n;j++){
        if(nums[j]!=nums[i]){
            nums[i+1] = nums[j];
            i++;
        }
    }

    cout<<i+1<<endl;
    return 0;
}