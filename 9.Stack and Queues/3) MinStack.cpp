#include<iostream>
using namespace std;

// tc: O(1)
// sc:O(2n)
class Minstack{
    stack<pair<int, int>> st;

    void push(int val){
        if (st.empty()){
            st.push({val, val}); // (12,12)
        }
        else{
            st.push({val, min(val, st.top().second)}); // (12,12),(15,12),(10,10);
        }
    }
    void getMin(){
        st.top().second;
    }
    void top(){
        st.top().first;
    }
};
//----------------------------------------------------------------------------------------------

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