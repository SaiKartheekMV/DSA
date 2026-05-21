#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    getline(cin, s);
    cin>>k;

    int maxLen = 0;
    int maxFreq = 0;
    vector<int>freq(26,0);
    int n = s.length();
    int i=0;
    for(int j=0;j<n;j++){
        freq[s[j]-'A']++;
        maxFreq = max(maxFreq, freq[s[j]-'A']);
        if(j-i+1 - maxFreq > k){
            freq[s[i]-'A']--;
            i++;
        }
        maxLen = max(maxLen, j-i+1);
    }
    cout<<maxLen<<endl;
    return 0;
}