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

// ---------------------------------------------------------------------------------------------------
class MinStack{
    stack<int>st;
    int mini = 1e9;

    void push(int val){
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val>mini) st.push(val);
            else{
                st.push(2*val - mini);
                mini = val;
            }
        }
    }
    void pop(){
        if(st.empty()) return;
        int x = st.top();
        st.pop();
        if(x < mini)  mini=(2*val - x);
    }

    int top(){
        if(st.empty()) return;
        int x = st.top();
        if(mini < x) return x;
        return mini;
    }
    int getMin(){
        return mini;
    } 
};
