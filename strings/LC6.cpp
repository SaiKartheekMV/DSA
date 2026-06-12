#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    int numRows;
    cin>>numRows;
    if(numRows == 1){
        cout<<s<<endl;
        return 0;
    }
    int n = s.length();
    vector<string>rows(numRows, "");
    int currentRow = 0;
    int direction = 1;

    for(int i=0;i<n;i++){
        rows[currentRow] += s[i];
        if(currentRow==0){
            direction = 1;
        }else if(currentRow == numRows-1){
            direction = -1;
        }

        currentRow += direction;
    }

    string ans = "";
    for(int i=0;i<numRows;i++){
        ans += rows[i];
    }
    cout<<ans<<endl;
    return 0;
}