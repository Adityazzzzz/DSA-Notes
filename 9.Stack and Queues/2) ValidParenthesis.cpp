#include<iostream>
using namespace std;

bool isValid(string s){
    stack<char> st;

    for(char it:s){
        if(it=='(' || it=='{' || it=='['){
            st.push(it);
        }
        else{
            if(st.empty()) return false;
            char top = st.top();
            st.pop();

            if((it==')' && top != '(') || (it=='}' && top != '{') || (it==']' && top != '[')){
                return false;
            }
        }
    }
    return st.empty();
}