#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    string t;
    getline(cin, t);
    int freq[26] = {0};

    for(char c : s){
        freq[c-'a']++;
    }

    for(char  c : t){
        freq[c-'a']--;
    }

    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            cout<<"false"<<endl;
            return 0;
        }
    }

    cout<<"true"<<endl;
    return 0;
}