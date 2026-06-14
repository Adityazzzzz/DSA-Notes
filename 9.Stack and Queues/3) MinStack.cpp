#include<iostream>
using namespace std;

class MinStack {
    stack<long long>st;
    long long mn;
public:
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mn = val;
        }
        else if(val>=mn) {
            st.push(val);
        }
        else {
            st.push(2LL*val-mn);
            mn = val;
        }
    }

    void pop() {
        if(st.top()<mn) mn = 2LL*mn-st.top();
        st.pop();
    }

    int top() {
        if(st.top()<mn) return mn;
        return st.top();
    }

    int getMin() {
        return mn;
    }
};