#include<iostream>
using namespace std;

string removeKdigits(string num,int k){
    string st;
    for(auto it : num){
        while(!st.empty() && k>0 && st.back()>it){
            st.pop_back();
            k--;
        }
        st.push_back(it);
    }
    while(k>0){
        st.pop_back();
        k--;
    }
    
    int i = 0;
    while(i<st.size() && st[i]=='0'){
        i++;
    }
        
    string ans = st.substr(i);
    return ans.empty() ? "0" : ans;
}
