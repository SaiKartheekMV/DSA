#include<bits/stdc++.h>
using namespace std;

string encode(vector<string>&strs){
    string ans = "";
    for(const string& s : strs){
        int n = s.length();
        string num  = to_string(n);
        ans += num;
        ans += "#";
        ans += s;
    }
    return ans;
}
vector<string>d;
vector<string>& decode(string& s){
    int i=0;
    while(i < s.length()){
        string len = "";
        while(s[i]!='#'){
            len += s[i];
            i++;
        }
        int num = stoi(len);
        i++;
        string a = s.substr(i, num);
        d.push_back(a);
        i+=num;
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string>strs(n);
    string s = "";
    for(int i=0;i<n;i++){
        getline(cin, s);
        strs.push_back(s);
    }
    string encoded = encode(strs);
    cout<<encoded<<endl;
    vector<string>decoded = decode(encoded);
    for(string a : decoded){
        cout<<a<<" ";
    }
    return 0;
}