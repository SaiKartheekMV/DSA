#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, k;
    cin>>m;
    unordered_map<string, int>mp;
    vector<string>id(m);
    for(int i=0;i<m;i++){
        cin>>id[i];
    }

    for(int i=0;i<m;i++){
        cin>>mp[id[i]];
    }

    cin>>k;
    int CartTotal=0;
    for(int i=0;i<k;i++){
        string s;
        int quant;
        cin>>s;
        cin>>quant;
        CartTotal = CartTotal + (mp[s]*quant);
    }
    cout<<"CartTotal:-"<<CartTotal<<endl;
    return 0;
}