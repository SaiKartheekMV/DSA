#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&routes, int source, int target, int n){
    if(source == target) return 0;
    unordered_map<int , vector<int>>stopToroute;
    for(int i=0;i<n;i++){
        for(int stop : routes[i]){
            stopToroute[stop].push_back(i);
        }
    }
    vector<int>visitedRoute(n, false);
    queue<int>q;
    for(int route : stopToroute[source]){
        q.push(route);
        visitedRoute[route] = true;
    }

    int steps = 1;

    while(!q.empty()){
        int size = q.size();

        while(size--){
            int route = q.front();
            q.pop();

            for(int stop : routes[route]){
                if(stop == target){
                    return steps;
                }
                for(int nextRoute : stopToroute[stop]){
                    if(visitedRoute[nextRoute]){
                        continue;
                    }
                    visitedRoute[nextRoute] = true;
                    q.push(nextRoute);
                }
            }
        }
        steps++;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, source, target;
    cin>>n;
    vector<vector<int>>routes(n, vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>routes[i][0]>>routes[i][1]>>routes[i][2];
    }
    cin>>source>>target;
    cout<<solve(routes, source, target, n)<<endl;
    return 0;
}