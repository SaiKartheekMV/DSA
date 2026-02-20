#include<bits/stdc++.h>
#include<sstream>
using namespace std;

string simplifyPath(string path){
    vector<string>simpath;
    string ans = "";
    stringstream ss(path);
    string token;
    while(getline(ss, token, '/')){
        if(token == "" || token =="."){
            continue;
        }
        if(token==".."){
            if(!simpath.empty()) simpath.pop_back();
        }
        else{
            simpath.push_back(token);
        }
    }

    for( string token : simpath){
        ans += "/"+token;
    }

    if(ans.empty()){
        return "/";
    }
    return ans;
}

int main(){
    string path;
    cin>>path;
    string ans = simplifyPath(path);
    cout<<ans<<endl;
    return 0;
}

