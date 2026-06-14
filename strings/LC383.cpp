#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string ransomNote, magazine;
    getline(cin, ransomNote);
    getline(cin, magazine);
    int freq[26] = {0};
    for(char ch : magazine){
        freq[ch-'a']++;
    }

    for(char ch : ransomNote){
        freq[ch-'a']--;
        if(freq[ch-'a']< 0){
            cout<<"False"<<endl;
            return 0;
        }
    }

    cout<<"True"<<endl;
    return 0;
}