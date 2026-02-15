#include<bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix){
    int maxArea = 0;
    if(matrix.size() == 0) return 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>heights(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == '1'){
                heights[j]+=1;
            }else{
                heights[j]=0;
            }
        }

        stack<int>st;
        int height = 0, width = 0;
        for(int k=0;k<heights.size();k++){
        while(!st.empty() && heights[k]<heights[st.top()]){
            int idx = st.top(); st.pop();
            height = heights[idx];

            if(st.empty()){
                width = k;
            }else{
                width = k - st.top() - 1;
            }
            maxArea = max(maxArea, height*width);
        }
        
        st.push(k);
    }
    while(!st.empty()){
        int idx = st.top(); st.pop();
        height = heights[idx];

        if(st.empty()){
            width = heights.size();
        }else{
            width = heights.size()-st.top()-1;
        }
        maxArea = max(maxArea, height*width);
    }
    }
    return maxArea;
}

int main(){
    int n,m,ans;
    cin>>n>>m;
    vector<vector<char>>matrix(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    ans = maximalRectangle(matrix);
    cout<<ans<<endl;
    return 0;
}