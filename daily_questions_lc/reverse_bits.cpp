#include<bits/stdc++.h>
using namespace std;


    int reverseBits(int n) {
        unsigned int result = 0;
        for(int i=0;i<32;i++ ){
            int bit = n & 1;
            result = result << 1;
            result = result | bit;
            n = n >> 1;
        }
        return result;
    }


    int main(){
        int n;
        cin>>n;
        int ans = reverseBits(n);
        cout<<ans<<endl;
        return 0;
    }

