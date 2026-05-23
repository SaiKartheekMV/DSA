#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<char, int>freqT;
    unordered_map<char, int>freqW;
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int i = 0;
    int minLen = INT_MAX;
    int have  = 0;
    for(char c : t){
        freqT[c]++;
    }
    int need = freqT.size();
    int start = 0;
    for(int j=0;j<s.length();j++){
        freqW[s[j]]++;
        if(freqT.count(s[j])&&freqW[s[j]]==freqT[s[j]]){
            have++;
        }
        while(have==need){
            if(j-i+1 < minLen){
                minLen = j-i+1;
                start = i;
            }
            freqW[s[i]]--;
            if(freqT.count(s[i]) && freqW[s[i]] < freqT[s[i]]){
                have--;
            }
            i++;
        }
    }
    minLen == INT_MAX ? cout<<""<<endl : cout<<s.substr(start, minLen)<<endl;
    return 0;
}