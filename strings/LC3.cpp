#include<bits/stdc++.h>
using namespace std;

int solve(string &s){
    int n = s.length();
    int left = 0;
    int len  = 0;
    unordered_set<int>st;
    for(int right = 0;right <= n;right++){
        while(st.find(s[right]) != st.end()){
            left++;
            st.erase(s[left]);
        }
        st.insert(s[right]);
        len = max(len, right-left+1);
    }
    return len;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    cout<<solve(s)<<endl;
    return 0;
}