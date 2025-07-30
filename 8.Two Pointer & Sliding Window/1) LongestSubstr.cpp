#include<bits/stdc++.h>
using namespace std;

// longest substr withut repeating char
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int left=0,right=0,maxlen=0;
    unordered_set<char>st;
    
    while(right<n){ 
        if(st.find(s[right])==st.end()){
            st.insert(s[right]);
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        else{
            st.erase(s[left]);
            left++;
        }
    }
    return maxlen;
}