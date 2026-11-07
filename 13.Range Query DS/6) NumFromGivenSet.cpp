#include<iostream>
using namespace std;

//recursive
int solve(int idx,bool tight,bool started,int mask){
    if(idx==s.size()) return started ? 1 : 0;

    int limit = tight ? s[idx]-'0' : 9;
    int res = 0;
    for(int d=0;d<=limit;d++){
        if(!started && d==0){
            res += solve(idx+1,false,false,mask);
        }
        else{
            if(!(mask & (1<<d))) continue;
            res += solve(idx+1,tight && (d==limit),true,mask);
        }
    }
    return res;
}
int atMostNGivenDigitSet(vector<string>& digits,int n){
    int mask = 0;
    for(auto it:digits){
        mask |= (1<<stoi(it));
    }

    string s = to_string(n);
    return solve(0,true,false,mask);
}

//memoization
string s;
int dp[11][2][2];
int mask;

int solve(int idx,bool tight,bool started){
    if(idx==s.size()) return started ? 1 : 0;
    if(dp[idx][tight][started] != -1) return dp[idx][tight][started];

    int limit = tight ? s[idx]-'0' : 9;
    int res = 0;

    for(int d=0;d<=limit;d++){
        if(!started && d==0){
            res += solve(idx+1,false,false);
        }
        else{
            if(!(mask & (1 << d))) continue;
            res += solve(idx+1,tight && (d == limit),true);
        }
    }

    return dp[idx][tight][started] = res;
}
int atMostNGivenDigitSet(vector<string>& digits,int n){
    mask = 0;
    for(auto it:digits){
        mask |= (1<<stoi(it));
    }
    s = to_string(n);
    memset(dp,-1,sizeof(dp));

    return solve(0,true,false);
}