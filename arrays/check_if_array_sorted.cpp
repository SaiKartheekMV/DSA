#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    if (n <= 1) {
        cout << "Array is sorted" << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "Array is not sorted" << endl;
            return 0;
        }
    }

    cout << "Array is sorted" << endl;
    return 0;
}
