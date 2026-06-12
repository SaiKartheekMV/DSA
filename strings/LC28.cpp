#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int n = s1.length();
    int m = s2.length();
    for(int i=0;i<n-m;i++){
        int j = 0;

        while(j<m){
            if(s1[i+j] != s2[j]){
                break;
            }
            j++;
        }


        if(j==m){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<"String not Found"<<endl;
    return 0;
}