#include<bits/stdc++.h>
using namespace std;


bool dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& board, int idx, string word){
    if(idx==word.length()){
        return true;
    }

    if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()){
        return false;
    }

    if(visited[r][c]){
        return false;
    }

    if(board[r][c]!=word[idx]){
        return false;
    }

    visited[r][c] = true;

    bool found = dfs(r+1, c, visited, board, idx+1, word) ||
                 dfs(r, c+1, visited, board, idx+1, word) ||
                 dfs(r-1, c, visited, board, idx+1, word) ||
                 dfs(r, c-1, visited, board, idx+1, word);
    
    visited[r][c] = false;
    return found;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    cin.ignore();
    string word;
    getline(cin, word);
    
    vector<vector<char>>board(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    
    vector<vector<bool>>visited(n, vector<bool>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i, j, visited, board, 0, word)){
                cout<<"String is Present"<<endl;
                return 0;
            }
        }
    }

    cout<<"String is not Present"<<endl;
    
    return 0;
}