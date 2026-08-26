#include<bits/stdc++.h>
using namespace std;
queue<pair<int, int>>q;
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

void dfs(vector<vector<int>>&grid, int r, int c, int n){
    grid[r][c] = 2;
    q.push({r, c});
    for(int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= 1 || nc < 0 || nc >=1 || grid[nr][nc] == 1){
            continue;
        }
        dfs(grid, nr, nc, n);
    }
}

int solve(vector<vector<int>>&grid, int n){
    bool found = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n && !found;j++){
            if(grid[i][j] == 1){
                dfs(grid, i, j, n);
                found = true;
            }
        }
    }
    int steps = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto[r, c] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc]==2){
                    continue;
                }

                if(grid[nr][nc]==1){
                    return steps;
                }

                grid[nr][nc] = 2;
                q.push({nr, nc});
            }
        }
        steps++;
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
    cout<<solve(grid, n)<<endl;
    return 0;
}