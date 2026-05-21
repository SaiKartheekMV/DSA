#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    getline(cin, s);
    int i = 0;
    int len  = 0;
    set<char>st;
    int n = s.length();
    for(int j=0;j<n;j++){
        while(st.find(s[j])!=st.end()){
            st.erase(s[i]);
            i++;
        }
        st.insert(s[j]);
        len = max(len, j-i+1);
    }
    cout<<len<<endl;
    return 0;
}