#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>& solve(vector<vector<int>>&mat, int m, int n){
    queue<pair<int, int>>q;
    vector<vector<int>>dist(m, vector<int>(n, -1));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 0){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(!q.empty()){
        auto[r,c] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n){
                continue;
            }

            if(dist[nr][nc] != -1){
                continue;
            }

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin>>m>>n;
    vector<vector<int>>mat(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>result = solve(mat, m, n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}