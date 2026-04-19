#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j){
    if(i<0 || i>=grid.size()) return ;
    if(j<0 || j>=grid[0].size()) return ;
    if(grid[i][j] == '0') return ;
    grid[i][j] = '0';
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
}

int numIslands(vector<vector<char>>& grid){
    int cnt = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                cnt++;
                dfs(grid, i, j);
            }
        }
    }
    return cnt;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int ans = numIslands(grid);
    cout<<ans<<endl;
    return 0;
}