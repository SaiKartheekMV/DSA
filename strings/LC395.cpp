#include<bits/stdc++.h>
using namespace std;

int solve(string& s, int k){
    int ans = 0;
    for(int targetK = 1;targetK<=26;targetK++){
        int l = 0;
        int dist = 0, atlK = 0;
        vector<int>freq(26, 0);
        int n = s.size();
        for(int r=0;r<n;r++){
            freq[s[r]-'a']++;
            if(freq[s[r]-'a']==1){
                dist++;
            }

            if(freq[s[r]-'a']==k){
                atlK++;
            }

            while(dist > targetK){
                freq[s[l]-'a']--;

                if(freq[s[l]-'a']==0){
                    dist--;
                }

                if(freq[s[l]-'a']==k-1){
                    atlK--;
                }

                l++;
            }

            if(dist == atlK){
                ans = max(ans, r-l+1);
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    int k;
    cin>>k;
    cout<<solve(s, k)<<endl;
    return 0;
}