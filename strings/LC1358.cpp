#include<bits/stdc++.h>
using namespace std;

int solve(string& s){
    int n = s.size();
    int lastA = -1, lastB = -1, lastC = -1;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i]== 'a'){
            lastA = i;
        }

        if(s[i]=='b'){
            lastB = i;
        }

        if(s[i]=='c'){
            lastC = i;
        }
        
        int lastValid = min(lastA, min(lastB, lastC));
        ans += lastValid + 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    cout<<solve(s)<<endl;
    return 0;
}