#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string num;
    getline(cin, num);
    int sum = 0;
    bool doubleDigit = false;

    for(int i = num.length()-1;i>=0;i--){
        int digit = num[i]-'0';

        
       if(doubleDigit){
        digit*=2;
        if(digit > 9){
            digit -= 9;
        }
       }
        sum+=digit;
        doubleDigit = !doubleDigit;
    }

    sum % 10 == 0 ? cout<<"Card is Valid\n" : cout<<"Card is Not Valid"<<endl;
    return 0;
}