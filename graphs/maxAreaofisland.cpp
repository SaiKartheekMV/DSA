#include<bits/stdc++.h>
using namespace std;



int dfs(vector<vector<int>>&grid, int i, int j){
    if(i < 0 || i >= grid.size()) return 0;
    if(j < 0 || j >= grid[0].size()) return 0;
    if(grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    int cntArea = 1 + dfs(grid, i, j-1) + dfs(grid, i, j-1) + dfs(grid, i-1, j) + dfs(grid, i+1, j);
    return cntArea;
}

int maxAreaIsland(vector<vector<int>>&grid){
    int maxArea = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                int cntArea = dfs(grid, i, j);
                maxArea = max(cntArea, maxArea);
            }
        }
    }
    return maxArea;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<vector<int>>grid(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<maxAreaIsland(grid)<<endl;
    return 0;
}


