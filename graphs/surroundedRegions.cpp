#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& board, int i, int j){
    if(i < 0 || i >=board.size()) return ;
    if(j < 0 || j >=board[0].size()) return ;
    if(board[i][j]== 'X' || board[i][j] == 'S') return ;
    board[i][j] = 'S';
    dfs(board, i, j-1);
    dfs(board, i, j+1);
    dfs(board, i-1, j);
    dfs(board, i+1, j);
}


void solve (vector<vector<char>>&board){
    for(int j=0;j<board[0].size();j++){
        if(board[0][j] == 'O'){
            dfs(board, 0, j);
        }
    }

    for(int j=0;j<board[0].size();j++){
        if(board[board.size()-1][j] == 'O'){
            dfs(board, board.size()-1, j);
        }
    }

    for(int i=0;i<board.size();i++){
        if(board[i][0]=='O'){
            dfs(board, i, 0);
        }
    }

    for(int i=0;i<board.size();i++){
        if(board[i][board[0].size()-1] == 'O'){
            dfs(board, i, board[0].size()-1);
        }
    }

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='O'){
                board[i][j] = 'X';
            }else if(board[i][j]=='S'){
                board[i][j] = 'O';
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char>>board(n , vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    
    solve(board);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}