#include<iostream>
using namespace std;

//Ques - Count Number of Digit One in [0,R]

//recursive
int solve(string &s,int ind,bool tight,int cnt){
    if(ind == s.size()) return cnt;

    int ub = tight? s[ind]-'0' : 9;
    int ans = 0;
    for(int d=0;d<=ub;d++){
        bool newTight = tight && (d == s[ind]-'0');
        ans += solve(ind+1,newTight,cnt+(d==1));
    }
    return ans;
}

//memoization
int solve(string &s,int &dp[][][],int ind,bool tight,int cnt){
    if(ind == s.size()) return cnt;
    if(dp[ind][tight][cnt] != -1) return dp[ind][tight][cnt];

    int ub = tight? s[ind]-'0' : 9;
    int ans = 0;
    for(int d=0;d<=ub;d++){
        bool newTight = tight && (d == s[ind]-'0');
        ans += solve(ind+1,dp,newTight,cnt+(d==1));
    }
    return dp[ind][tight][cnt] = ans;
}

//--------------------------------------------------------------------------------------------------
//Ques - Numbers with Repeated Digits

