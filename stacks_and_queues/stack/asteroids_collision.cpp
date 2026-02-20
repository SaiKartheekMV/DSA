#include<bits/stdc++.h>
using namespace std;

vector<int>asteroidCollision(vector<int>& asteroids){
    stack<int>st;
    for(int x:asteroids){
        bool alive = true;

        while(alive && !st.empty() && st.top() > 0 && x < 0){
            if(abs(st.top())<abs(x)){
                st.pop();
            }
            else if(abs(st.top()) == abs(x)){
                alive = false;
                st.pop();
            }
            else{
                alive = false;
            }
        }

        if(alive){
            st.push(x);
        }
    }

    vector<int>ans(st.size());
    for(int i = ans.size()-1;i>=0;i--){
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}


int main(){
    int n;
    cin>>n;
    vector<int>asteroids(n);
    for(int i=0;i<n;i++){
        cin>>asteroids[i];
    }
    vector<int>ans = asteroidCollision(asteroids);
    for(int a:ans){
        cout<<a<<" ";
    }
    return 0;
}