#include<bits/stdc++.h>
using namespace std;

int solve(vector<char>&tasks, int n){
    vector<int>freq(26, 0);
    for(char c : tasks){
        freq[c-'A']++;
    }
    int ans = 0;
    priority_queue<int>pq;
    for(int x : freq){
        if(x > 0){
            pq.push(x);
        }
    }
    while(!pq.empty()){
        vector<int>temp;
        int cycle = 0;
        for(int i=0; i <= n && !pq.empty(); i++){
            cycle++;
            int count = pq.top();
            pq.pop();

            count--;

            if(count>0){
                temp.push_back(count);
            }
        }

        for(int count : temp){
            pq.push(count);
        }

        if(pq.empty()){
            ans += cycle;
        }else{
            ans += n+1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin>>m;
    vector<char>tasks(m);
    for(int i=0;i<m;i++){
        cin>>tasks[i];
    }
    cin>>n;
    cout<<solve(tasks, n)<<endl;
    return 0;
}