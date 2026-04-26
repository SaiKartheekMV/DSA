#include<bits/stdc++.h>
using namespace std;


int rottenOranges(vector<vector<int>>&grid){
    int fresh_cnt = 0;
    queue<pair<int, int>>q;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                fresh_cnt++;
            }else if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    if(fresh_cnt==0) return 0;

    int minutes = 0;
    vector<vector<int>>directions = {{0,-1},{0,1},{-1,0},{1,0}};

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto& dir : directions){
                int nr = r + dir[0];
                int nc = c + dir[1];
                if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) continue;
                if(grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    fresh_cnt--;
                    q.push({nr,nc});
                }
            }
        }
        minutes++;
    }
    return fresh_cnt == 0 ? minutes - 1: -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    vector<vector<int>>grid(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int ans =  rottenOranges(grid);
    cout<<ans<<endl;
    return 0;
}