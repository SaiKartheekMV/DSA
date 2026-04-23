#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>directions = {{0,-1},{0,1}, {-1,0},{1,0}};

void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>&visited){
    visited[r][c] = true;
    for(auto&dir : directions){
        int nr = r + dir[0];
        int nc = r + dir[1];

        if(nr < 0 || nr >= heights.size() || nc < 0 || nc >= heights[0].size()) continue;
        if(visited[nr][nc]) continue;

        if(heights[nr][nc] >= heights[r][c]){
            dfs(nr, nc, heights, visited);
        }
    }
}


vector<vector<int>>pacificAtlantic(vector<vector<int>>& heights){
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<bool>>pacific(m, vector<bool>(n, false));
    vector<vector<bool>>atlantic(m, vector<bool>(n, false));

    for(int i=0;i<m;i++){
        dfs(i, 0, heights, pacific);
        dfs(i, n-1, heights, atlantic);
    }

    for(int j=0;j<n;j++){
        dfs(0, j, heights, pacific);
        dfs(m-1, j, heights, atlantic);
    }
    
    vector<vector<int>>result;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pacific[i][j] && atlantic[i][j]){
                result.push_back({i,j});
            }
        }
    }
    return result;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    vector<vector<int>>heights(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>heights[i][j];
        }
    }
    vector<vector<int>>result = pacificAtlantic(heights);
   for(auto& pair : result){
    cout << "[" << pair[0] << "," << pair[1] << "]" << endl;
}
    return 0;
}
