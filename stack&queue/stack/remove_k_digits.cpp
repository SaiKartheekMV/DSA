#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;

    for(char c : num) {
        while(!st.empty() && c < st.top() && k > 0) {
            st.pop();
            k--;
        }
        st.push(c);
    }

    while(k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    string ans = "";
    while(!st.empty()) {
        char c = st.top();
        ans.push_back(c);
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    int i = 0;
    while(i < ans.size() && ans[i] == '0') {
        i++;
    }

    ans = ans.substr(i);

    if(ans.empty()) return "0";

    return ans;
}

int main(){
    int k;
    cin>>k;
    string num;
    cin>>num;
    string ans = removeKdigits(num, k);
    cout<<ans<<endl;
    return 0;
}