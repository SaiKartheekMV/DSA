#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans(nums.size()+1, 0);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        ans[i] = sum;
    }
    cout<<*max_element(ans.begin(), ans.end())<<endl;
    return 0;
}