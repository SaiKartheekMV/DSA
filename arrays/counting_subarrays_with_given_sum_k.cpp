#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;

    unordered_map<int,int> mp;
    mp[0] = 1;   

    int sum = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];

        if(mp.find(sum - k) != mp.end()){
            count += mp[sum - k];
        }

        mp[sum]++;
    }

    cout << count << endl;
    return 0;
}
