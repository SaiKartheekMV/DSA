#include<bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    stack<char>st;

    for(char c:s){
        if(st.empty()){
            st.push(c);
        }else if(c == st.top()){
            st.pop();
        }else{
            st.push(c);
        }
    }

    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s, ans;
    cin>>s;
    ans  = removeDuplicate(s);
    cout<<ans<<endl;
    return 0;
}