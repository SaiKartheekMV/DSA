#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>>&maze, int m, int n, int e1, int e2){
    queue<pair<int, int>>q;
    vector<vector<int>>visited(m, vector<int>(n, false));
    visited[e1][e2] = true;
    q.push({e1, e2});
    int steps = 0;
    int dr[] = {0,0,-1,1};
    int dc[] = {1,-1,0,0};
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto[r, c] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= m ||nc < 0 || nc >= n || (nr == e1 && nc == e2)){
                    continue;
                }

                if(maze[nr][nc]=='+'){
                    continue;
                }

                if(visited[nr][nc]){
                    continue;
                }

                if(nr==0 || nr ==m-1 || nc == 0 || nc == n-1){
                    return steps + 1;
                }

                visited[nr][nc] = true;
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
    int m, n;
    cin>>m>>n;
    vector<vector<char>>maze(m, vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    int e1, e2;
    cin>>e1>>e2;
    cout<<solve(maze, m, n, e1, e2)<<endl;
    return 0;
}