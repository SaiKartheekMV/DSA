#include<bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<pair<string, int>>st;
    string curr_string = "";
    int curr_num = 0;

    for(char c : s){
        if(isdigit(c)){
            curr_num = curr_num*10+(c-'0');
        }else if(c=='['){
            st.push({curr_string, curr_num});
            curr_string = "";
            curr_num = 0;
        }else if(c==']'){
            auto p = st.top();
            st.pop();
            string prev_string = p.first;
            int rep_count = p.second;

            string temp = "";
            for(int i=0;i<rep_count;i++){
                temp += curr_string;
            }

            curr_string = prev_string + temp;
        }else{
            curr_string += c;
        }
    }
    return curr_string;
}
int main(){
    string s;
    cin>>s;
    string ans = decodeString(s);
    cout<<ans<<endl;
    return 0;
}