#include<iostream>
#include<sstream>
using namespace std;

int main(){
    string path = "/home//foo/";
    stringstream ss(path);
    string token;
    while(getline(ss, token, '/')){
        cout<<"["<<token<<"]"<<endl;
    } 
    return 0;
}