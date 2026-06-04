// Lab 3 - Array Analytics: Maximum Subarray + Equilibrium Index
#include<bits/stdc++.h>
using namespace std;
// This function contains a BUG. Find it and fix it.
long long maxSubarraySum(const vector<long long>& a) {
 long long best = a[0], cur = a[0];
 for (size_t i = 1; i < a.size(); i++) { 
    cur = max(a[i], cur+a[i]);
    best = max(cur, best); 
}
 return best;
}
// TODO: Implement this function from scratch.
// Return the first index where the sum to its left equals the sum to its
// right (excluding the index), or -1.
int equilibriumIndex(const vector<long long>& a) {
   int totalSum = accumulate(a.begin(), a.end(), 0);
   int rightSum = 0, leftSum = 0;
   for(int i=0;i<a.size();i++){
    rightSum = totalSum-leftSum-a[i];
    if(rightSum==leftSum){
        return i;
    }
    leftSum+=a[i];
   }
   return -1;
}
int main() {
 int n; cin >> n;
 vector<long long> a(n);
 for (int i = 0; i < n; i++) cin >> a[i];
 cout << "Max Subarray Sum: " << maxSubarraySum(a) << "\n";
 cout << "Equilibrium Index: " << equilibriumIndex(a) << "\n";
 return 0;
}