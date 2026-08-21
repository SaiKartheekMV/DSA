#include<bits/stdc++.h>
using namespace std;

string solve(string& s, int l, int r){
    if( l > r) return "";
    vector<bool>present(128, false);
    for(int i=l;i<=r;i++){
        present[s[i]] = true;
    }

    for(int i=l;i<=r;i++){
        char low = tolower(s[i]);
        if(!present[low] || !present[toupper(low)]){
            string left = solve(s, l, i-1);
            string right = solve(s, i+1, r);

            return left.size() >= right.size() ? left : right;
        }
    }
    return s.substr(l, r-l+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    cout<<solve(s, 0, s.length()-1)<<endl;
    return 0;
}