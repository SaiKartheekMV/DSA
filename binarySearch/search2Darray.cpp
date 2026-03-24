#include<bits/stdc++.h>
using namespace std;

bool search2Darray(vector<vector<int>>&matrix, int target){
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0;
    int high = rows*cols-1;

    while(low<=high){
        int mid = low + (high - low) / 2;
        int i = mid / cols;
        int j = mid % cols;
        if(matrix[i][j]==target){
            return true;
        }else if(matrix[i][j]<target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int target;
    cin>>target;
    cout<<search2Darray(matrix, target)<<endl;
    return 0;
}