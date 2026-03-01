#include<bits/stdc++.h>
using namespace std;

bool validPalindrome(string s){
    int l=0;
    int r=s.length()-1;

    while(l<r){
       if(!isalnum(s[l])){
        l++;
       }else if(!isalnum(s[r])){
        r--;
       }else{
        if(tolower(s[l]) != tolower(s[r])){
            return false;
        }
        l++;
        r--;
       }
    }
    return true;
}


int main(){
    string s;
    cin>>s;
    if(validPalindrome(s)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}