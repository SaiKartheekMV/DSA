#include<bits/stdc++.h>
using namespace std;

double medianOfArrays(vector<int>&nums1, vector<int>&nums2){
    if(nums1.size() > nums2.size()){
        return medianOfArrays(nums2, nums1);
    }
    int m = nums1.size();
    int n = nums2.size();

    int low = 0;
    int high = m;


    while(low<=high){
        int mid1 = low + (high-low) / 2;
        int mid2 = (m+n+1) / 2 -mid1;

        int l1 = (mid1==0) ? INT_MIN : nums1[mid1-1];
        int r1 = (mid1==m) ? INT_MAX : nums1[mid1];
        int l2 = (mid2==0) ? INT_MIN : nums2[mid2-1];
        int r2 = (mid2==n) ? INT_MIN : nums2[mid2];


        if(l1 <= r2 && l2 <= r1){
            if((m+n)%2 == 0){
                return (max(l1,l2) + min(r1,r2)) / 2.0;
            } else{
                return max(l1, l2);
            }
        }else if(l1 > r2){
            high = mid1-1;
        }else{
            low = mid1+1;
        }
    }
    return 0.0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<int>nums1(n);
    vector<int>nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    cout<<setprecision(4)<<medianOfArrays(nums1, nums2)<<endl;
    return 0;
}