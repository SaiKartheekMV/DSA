#include<bits/stdc++.h>
using namespace std;

vector<string>ans;

unordered_map<int, string>mp{
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tvu"},
    {9, "wxyz"}
};

void solve(int idx, string t, string digits){
    if(idx==digits.length()){
        ans.push_back(t);
        return ;
    }

    int currDigit = digits[idx]-'0';
    string letters = mp[currDigit];

    for(int i=0;i<letters.length();i++){
        t.push_back(letters[i]);
        solve(idx+1, t, digits);
        t.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string digits;
    getline(cin, digits);
    string t = "";
    solve(0, t, digits);
    for(auto& x : ans){
        cout<<x<<" ";
    }
    return 0;
}