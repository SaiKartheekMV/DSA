#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&nums, int n, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left < n && nums[left] > nums[largest]){
        largest = left;
    }

    if(right < n && nums[right] > nums[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int>&nums){
    int n = nums.size();

    for(int i=n/2 - 1; i>=0;i--){
        heapify(nums, n, i);
    }

    for(int i=n-1;i>0;i--){
        swap(nums[0], nums[i]);
        heapify(nums,i, 0);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    heapSort(nums);
    for(int num : nums){
        cout<<num<<" ";
    }
    return 0;
}


