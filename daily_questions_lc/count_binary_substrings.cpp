#include<bits/stdc++.h>
using namespace std;

int cntBinarySubStr(string s){
    int ans = 0;
    int prev = 0, curr = 1;
    for(int i=1;i<=s.length()-1;i++){
        if(s[i]==s[i-1]){
            curr++;
        }else{
            ans += min(prev, curr);
            prev = curr;
            curr = 1;
        }
    }
    ans += min(prev, curr);
    return ans;
}

int main(){
    string s;
    cin>>s;
    int ans  = cntBinarySubStr(s);
    cout<<ans<<endl;
    return 0;
}