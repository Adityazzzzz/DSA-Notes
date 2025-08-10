#include<bits/stdc++.h>
using namespace std;

int func(string s,int k){
    int l=0,r=0,maxlen=0,maxfreq=0;
    map<char,int>mpp;

    while(r < s.size()){
        mpp[s[r]]++;
        if(mpp.size() > k){
            hash[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(mpp[s[l]]);
            l++;
        }
        if(mpp.size() <= k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
}