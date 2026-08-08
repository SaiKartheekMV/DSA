#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&tokens, int power){
    sort(tokens.begin(), tokens.end());
    int score = 0 , best = 0;
    int i = 0;
    int j = tokens.size()-1;
    while(i<=j){
        if(tokens[i]<=power){
            power-=tokens[i];
            i++;
            score++;
            best =  max(best, score);
        }else if(score >= 1){
            power+=tokens[j];
            j--;
            score--;
            best =  max(best, score);
        }else{
            break;
        }
    }
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,power;
    cin>>n;
    vector<int>tokens(n);
    for(int i=0;i<n;i++){
        cin>>tokens[i];
    }
    cin>>power;
    cout<<solve(tokens, power);
    return 0;
}