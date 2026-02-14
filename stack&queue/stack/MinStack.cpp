#include<bits/stdc++.h>
using namespace std;

class Minstack{
    public:
    stack<pair<int, int>>st;
    Minstack(){

    }

    void push(int val){
        if(st.empty()){
            st.push({val, val});
        }else{
            int newMin = min(val, st.top().second);
            st.push({val, newMin});
        }
    }

    void pop(){
        st.pop();
    }

    int top(){
        return st.top().first;
    }

    int getMin(){
        return st.top().second;
    }
};

int main() {
    Minstack* obj = new Minstack();

    obj->push(5);
    obj->push(3);
    obj->push(7);
    obj->push(2);

    cout << obj->top() << endl;
    cout << obj->getMin() << endl;

    obj->pop();

    cout << obj->top() << endl;
    cout << obj->getMin() << endl;

    delete obj;
    return 0;
}
