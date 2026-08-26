#include<bits/stdc++.h>
using namespace std;

int solve(string& beginWord, string& endWord, vector<string>& wordList, int n){
    unordered_set<string>words(wordList.begin(), wordList.end());
    if(!words.count(endWord)){
        return 0;
    }
    int steps = 1;
    queue<string>q;
    q.push(beginWord);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            string word = q.front();
            q.pop();

            if(word == endWord){
                return steps;
            }

            for(int i=0;i<word.length();i++){
                char original = word[i];

                for(char ch = 'a';ch <= 'z';ch++){
                    if(ch == original){
                        continue;
                    }

                    word[i] = ch;

                    if(endWord == word){
                        return steps+1;
                    }

                    if(words.count(word)){
                        words.erase(word);
                        q.push(word);
                    }
                }
                word[i] = original;
            }
        }
        steps++;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string beginWord, endWord;
    getline(cin, beginWord);
    getline(cin, endWord);
    cin>>n;
    vector<string>wordList(n);
    for(int i=0;i<n;i++){
        getline(cin, wordList[i]);
    }
    cout<<solve(beginWord, endWord, wordList, n)<<endl;
    return 0;
}