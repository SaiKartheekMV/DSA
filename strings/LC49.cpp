#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cin.ignore();
    vector<string>strs;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        strs.push_back(s);
    }

    vector<vector<string>>ans;

    unordered_map<string, vector<string>>mp;

    for(const string&s : strs){
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }

    for(auto& it : mp){
        ans.push_back(it.second);
    }

    for(const auto& group : ans){
        cout<<"[";

        for(const string& word : group){
            cout<<word<<" ";
        }

        cout<<"]"<<endl;
    }
    return 0;
}