#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    int l = 0;
    int r = s.length()-1;

    while(l<r){
        if(!isalnum(s[l])){
            l++;
        }else if(!isalnum(s[r])){
            r--;
        }else{
            if(tolower(s[l])!=tolower(s[r])){
                cout<<"false"<<endl;
                return 0;
            }
            l++;
            r--;
        }  
    }
    cout<<"true"<<endl;
    return 0;
}