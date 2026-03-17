#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool canMake(int day, vector<int>&bloomDay, int k, int m){
            int bouquet = 0;
            int count = 0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=day){
                    count++;
                   
                    if(count == k){
                    bouquet++;
                    count = 0;
                    }
                }
                 else{
                    count = 0;
                }
            }
            return (bouquet >= m);
        }







    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()){
            return -1;
        }

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;

        while(low<=high){
            int mid = low + (high - low) / 2;
            
            if(canMake(mid, bloomDay, k, m)==true){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> bloomDay(n);
    for(int i = 0; i < n; i++){
        cin >> bloomDay[i];
    }

    int m, k;
    cin >> m >> k;

    Solution obj;
    int result = obj.minDays(bloomDay, m, k);

    cout << result << "\n";

    return 0;
}