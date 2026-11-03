#include<iostream>
using namespace std;

//Ques - Count Number of Digit One in [0,R]

// DP states:
// - i: Current digit position
// - tight: Whether we're restricted by n
// - cnt: number of digit one

//recursive
int solve(string &s,int i,bool tight,int cnt){
    if(i==s.size()) return cnt;

    int limit = tight? s[i]-'0' : 9;
    int ans = 0;
    for(int d=0;d<=limit;d++){
        bool newTight = tight && (d == s[i]-'0');
        ans += solve(i+1,newTight,cnt+(d==1));
    }
    return ans;
}

//memoization
int solve(string &s,int &dp[][][],int i,bool tight,int cnt){
    if(i==s.size()) return cnt;
    if(dp[i][tight][cnt] != -1) return dp[i][tight][cnt];

    int limit = tight? s[i]-'0' : 9;
    int ans = 0;
    for(int d=0;d<=limit;d++){
        bool newTight = tight && (d == s[i]-'0');
        ans += solve(i+1,dp,newTight,cnt+(d==1));
    }
    return dp[i][tight][cnt] = ans;
}

//--------------------------------------------------------------------------------------------------
//Ques - Numbers with Repeated Digits

// DP states:
// - i: Current digit position
// - tight: Whether we're restricted by n
// - mask: Bitmask representing digits already used
// - started: Whether we've started forming the number (to ignore leading zeros)

int solve(int i,int tight,int mask,int started){
    if(i==s.size()) return started ? 1 : 0;

    int limit = tight ? s[i]-'0' : 9;
    int ans = 0;
    for(int d=0;d<=limit;d++){
        int newTight = tight && (d==limit);

        if(!started && d==0) ans += solve(i+1,newTight,mask,0);
        else{
            if(mask & (1<<d)) continue;
            ans += solve(i+1,newTight,mask | (1<<d),1);
        }
    }
    return ans;
}
int numDupDigitsAtMostN(int n){
    string s = to_string(n);
    return n - solve(0,1,0,0);
}

//memoization
string s;
int dp[11][2][1024][2];
int solve(int i,int tight,int mask,int started){
    if(i==s.size()) return started ? 1 : 0;
    if(dp[i][tight][mask][started] != -1) return dp[i][tight][mask][started];

    int limit = tight ? s[i]-'0' : 9;
    int ans = 0;
    for(int d=0;d<=limit;d++){
        int newTight = tight && (d==limit);

        if(!started && d==0) ans += solve(i+1,newTight,mask,0);
        else{
            if(mask & (1<<d)) continue;
            ans += solve(i+1,newTight,mask | (1<<d),1);
        }
    }
    return dp[i][tight][mask][started] = ans;
}
int numDupDigitsAtMostN(int n){
    s = to_string(n);
    memset(dp,-1,sizeof(dp));
    return n - solve(0,1,0,0);
}