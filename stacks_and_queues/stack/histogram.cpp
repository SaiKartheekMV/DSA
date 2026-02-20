#include<bits/stdc++.h>
using namespace std;

int areaHistogram(vector<int>& heights){
    stack<int>st;

    int area=0,height=0,width=0;

    for(int i=0;i<=heights.size()-1;i++){
        while(!st.empty() && heights[i]<heights[st.top()]){
            int idx = st.top(); st.pop();
            height = heights[idx];

            if(st.empty()){
                width = i;
            }else{
                width = i - st.top() - 1;
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
    int n;
    cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    int ans  = areaHistogram(heights);
    cout<<ans<<endl;
    return 0;
}