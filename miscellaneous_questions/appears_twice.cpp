#include<bits/stdc++.h>
using namespace std;

bool appearsTwice(vector<int>& nums){
    int n = nums.size();
    set<int>s;
    for(int i=0;i<n;i++){
        if(s.count(nums[i])){
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    if(appearsTwice(nums)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}