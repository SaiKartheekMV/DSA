#include<bits/stdc++.h>
using namespace std;

struct Product{
    string id;
    long long sales;
};

struct cmp{
    bool operator()(const Product &a, const Product &b){

        // Min Heap: worst product should stay on top

        if(a.sales != b.sales)
            return a.sales > b.sales;

        return a.id < b.id;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<Product, vector<Product>, cmp> pq;

    for(int i = 0; i < n; i++){

        Product p;
        cin >> p.id >> p.sales;

        pq.push(p);
    }

    int k;
    cin >> k;

    vector<Product> ans;

    while(!pq.empty() && ans.size() < k){
        ans.push_back(pq.top());
        pq.pop();
    }

    sort(ans.begin(), ans.end(), [](const Product &a, const Product &b){

        if(a.sales != b.sales)
            return a.sales > b.sales;

        return a.id < b.id;
    });

    for(auto &p : ans){
        cout << p.id << " " << p.sales << '\n';
    }

    return 0;
}