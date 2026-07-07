#include<bits/stdc++.h>
using namespace std;

void diagonalSort(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m =matrix[0].size();
    unordered_map<int, vector<int>>mp;
    unordered_map<int, int>idx;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mp[j-i].push_back(matrix[i][j]);
        }
    }

    for(auto& x : mp){
        sort(x.second.begin(), x.second.end());
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int key = j-i;
            matrix[i][j] = mp[key][idx[key]];
            idx[key]++;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<int>>matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    diagonalSort(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}