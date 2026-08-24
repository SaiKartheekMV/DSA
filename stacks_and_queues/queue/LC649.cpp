#include<bits/stdc++.h>
using namespace std;

string solve(string& senate){
    int n = senate.size();
    queue<int>rq, dq;
    for(int i=0;i<n;i++){
        if(senate[i]=='R'){
            rq.push(i);
        }else{
            dq.push(i);
        }
    }

    while(!rq.empty() && !dq.empty()){
        int r = rq.front();
        int d = dq.front();

        if(r < d){
            rq.pop();
            dq.pop();
            rq.push(r+n);
        }else{
            dq.pop();
            rq.pop();
            dq.push(d+n);
        }
    }

    if(rq.empty()){
        return "Dire";
    }

    return "Radiant";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string senate;
    getline(cin, senate);
    cout<<solve(senate)<<endl;
    return 0;
}