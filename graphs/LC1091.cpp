#include<bits/stdc++.h>
using namespace std;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        if(grid[0][0]==1) return -1;
        if(grid[grid.size()-1][grid.size()-1]==1) return -1;
        q.push({0,0});
        grid[0][0] = 1;
        int distance = 1;
        vector<vector<int>>directions = {{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if(r == grid.size()-1 && c == grid[0].size()-1) return distance;
                for(auto& dir : directions){
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if(nr < 0 || nr >= grid.size() || nc < 0 || nc >=grid[0].size()) continue;
                    if(grid[nr][nc]==0){
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            distance++;
        }
        return -1;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin>>n;
        vector<vector<int>>grid(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        int ans = shortestPathBinaryMatrix(grid);
        cout<<ans<<endl;
        return 0;
    }