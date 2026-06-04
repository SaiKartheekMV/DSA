#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num1, num2;
    cin>>num1>>num2;
    int ans = 0;
    for(int num=num1;num<=num2;num++){
        string s = to_string(num);
        if(s.length()< 3){
            continue;
        }
        for(int i=1;i<s.length()-1;i++){
            bool peak = s[i] > s[i-1] && s[i] > s[i+1];
            bool valley = s[i] < s[i-1] && s[i] < s[i+1];

            if(peak || valley){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}