#include<iostream>
using namespace std;

void expand(string &s,int left,int right,int &maxl,int &start){
    while(left>=0 && right<s.size() && s[left]==s[right]){
        left--;
        right++;
    }
    if(maxl < right-left-1){
        maxl = right-left-1;
        start = left+1;
    }
}
string longestPalindrome(string s){
    if (s.size() <= 1) return s;
    int maxl = 0,start = 0;
    
    for(int i=0;i<s.size();i++){
        expand(s,i,i,maxl,start);
        expand(s,i,i+1,maxl,start);
    }
    return s.substr(start,maxl);
}