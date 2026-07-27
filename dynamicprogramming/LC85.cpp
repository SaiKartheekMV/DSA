#include<bits/stdc++.h>
using namespace std;

int solve(int m, int n, vector<int>&heights){
    stack<int>st;
    int area=0, height=0, width=0;
    for(int i=0;i<heights.size();i++){
        while(!st.empty() && heights[i]<heights[st.top()]){
            int idx = st.top(); st.pop();
            height = heights[idx];

            if(st.empty()){
                width = i;
            }else{
                width = i-st.top()-1;
            }
            area = max(area, height*width);
        }
        st.push(i);
    }

    while(!st.empty()){
        int idx = st.top(); st.pop();
        height = heights[idx];

        if(st.empty()){
            width = heights.size();
        }else{
            width = heights.size()-st.top()-1;
        }
        area = max(area, height*width);
    }
    return area;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    int ans = 0;
    vector<vector<int>>matrix(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    vector<int>heights(n, 0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                heights[j] = 0;
            }else{
                heights[j]++;
            }
        }
        ans = max(ans, solve(m,n,heights));
    }
    cout<<ans<<endl;
    return 0;
}