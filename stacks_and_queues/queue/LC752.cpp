#include<bits/stdc++.h>
using namespace std;

int solve(vector<string>&dead, string& target){
    unordered_set<string>deadends(dead.begin(), dead.end());
    if(deadends.count("0000")){
        return -1;
    }
    unordered_set<string>visited;
    visited.insert("0000");
    queue<string>q;
    q.push("0000");
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            string current = q.front();
            q.pop();
            if(current == target){
                return count;
        
            }

            for(int i=0;i<4;i++){
                int digit = current[i] - '0';

                string next = current;
                next[i] = (digit + 1) % 10 + '0';
                if(!deadends.count(next) && !visited.count(next)){
                    visited.insert(next);
                    q.push(next);
                }

                next = current;
                next[i] = (digit - 1 + 10) % 10 + '0';

                if(!deadends.count(next) && !visited.count(next)){
                    visited.insert(next);
                    q.push(next);
                }
            }
            count++;
        }
    }
    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string>dead(n);
    for(int i=0;i<n;i++){
        getline(cin, dead[i]);
    }
    string target;
    getline(cin, target);
    cout<<solve(dead, target)<<endl;
    return 0;
}