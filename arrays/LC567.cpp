#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    int n1, n2;
    getline(cin, s1);
    getline(cin, s2);
    n1 = s1.length();
    n2 = s2.length();
    vector<int>freq1(26, 0);
    vector<int>freq2(26, 0);

    for(int i=0;i<n1;i++){
        freq1[s1[i]-'a']++;
    }

    int i = 0;

    for(int j=0;j<n2;j++){
        freq2[s2[j]-'a']++;
        if(j>=n1){
            freq2[s2[i]-'a']--;
            i++;
        }

        if(freq1==freq2){
            cout<<"true"<<endl;
            return 0;
        }
    }

    cout<<"false"<<endl;
    return 0;
}