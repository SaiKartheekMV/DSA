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
    int cnt1 = 0, cnt2 = 0, el1  = INT_MIN, el2 = INT_MIN;
    for(int num : nums){
        if(cnt1==0&&el2!=num){
            cnt1 = 1;
            el1 = num;
        }else if(cnt2==0&&el1!=num){
            cnt2 = 1;
            el2 = num;
        }else if(el1==num){
            cnt1++;
        }else if(el2 == num ){
            cnt2++;
        }
    }

    vector<int>ans;
    cnt1 = 0, cnt2 = 0;
    for(int num : nums){
        if(num==el1){
            cnt1++;
        }else if(num==el2){
            cnt2++;
        }
    }

    int mini = (int) (nums.size() / 3) + 1;
    if(cnt1 >= mini) ans.push_back(el1);
    if(cnt2 >= mini) ans.push_back(el2);
    for(int a : ans){
        cout<<a<<" ";
    }
    return 0;
}