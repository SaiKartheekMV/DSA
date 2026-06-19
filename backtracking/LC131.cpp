#include<bits/stdc++.h>
using namespace std;

vector<vector<string>>ans;


bool isPalindrome(string t){
    string u = t;
    reverse(u.begin(), u.end());
    if(u==t){
        return true;
    }
    return false;
}

void solve(int idx, vector<string>&temp, string s){
    string t = "";
    if(idx==s.length()){
        ans.push_back(temp);
        return ;
    }

    for(int i=idx;i<s.length();i++){
        t += s[i];
        if(isPalindrome(t)){
            temp.push_back(t);
            solve(idx+1, temp, s);
            temp.pop_back();
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    vector<string>temp;
    solve(0, temp, s);
    for(auto& rows : ans){
        cout<<"[";
        for(auto& x : rows){
            cout<<x<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}