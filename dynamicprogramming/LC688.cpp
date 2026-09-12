#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, row, column;
    cin>>n>>k>>row>>column;
    vector<vector<vector<double>>>dp(
        k+1,
        vector<vector<double>>(
            n,
            vector<double>(n)
        )
    );
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[0][i][j] = 1;
        }
    }
    vector<pair<int, int>>moves = {
        {1,2}, {1,-2}, {-1, 2}, {-1, -2},
        {2,1}, {2,-1}, {-2, 1}, {-2, -1}
    };
    for(int step=1;step<=k;step++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double sum = 0;

                for(auto& move : moves){
                    int ni = i+move.first;
                    int nj = j+move.second;

                    if(ni >= 0 && ni < n && nj >= 0 && nj < 0){
                        sum += dp[step-1][ni][nj];
                    }
                    dp[step][i][j] = sum / 8.0;
                }
            }
        }
    }
    cout << (double)dp[k][row][column] << endl;   
    return 0;
}