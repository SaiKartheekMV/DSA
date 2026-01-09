#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            if (ans.empty() || ans.back() != arr2[j]) {
                ans.push_back(arr2[j]);
            }
            j++;
        }
        else {
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n) {
        if (ans.back() != arr1[i]) {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m) {
        if (ans.back() != arr2[j]) {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
