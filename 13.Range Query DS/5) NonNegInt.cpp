#include<iostream>
using namespace std;

//recursive
string s;
int solve(int i,int tight,int prev){
    if(i==s.size()) return 1;

    int limit = tight ? s[i]-'0' : 1;
    int ans = 0;
    for(int d=0;d<=limit;d++){
        if(prev==1 && d==1) continue;

        int newTight = tight && (d==(s[i]-'0'));
        ans += solve(i+1,newTight,d);
    }
    return ans;
}

int findIntegers(int n){
    s = "";
    for(int i=31;i>=0;i--){
        if((n>>i) & 1){
            for(int j=i;j>=0;j--){
                s += char('0' + ((n>>j) & 1));
            }
            break;
        }
    }
    if(s.empty()) s = "0";
    return solve(0,1,0);
}

//memoization
string s;
int dp[32][2][2];
int solve(int i,int tight,int prev){
    if(i==s.size()) return 1;
    if(dp[i][tight][prev] != -1) return dp[i][tight][prev];

    int limit = tight ? s[i]-'0' : 1;
    int ans = 0;
    for(int d=0;d<=limit;d++){
        if(prev==1 && d==1) continue;

        int newTight = tight && (d==(s[i]-'0'));
        ans += solve(i+1,newTight,d);
    }
    return dp[i][tight][prev] = ans;
}

int findIntegers(int n){
    s = "";
    for(int i=31;i>=0;i--){
        if((n>>i) & 1){
            for(int j=i;j>=0;j--){
                s += char('0' + ((n>>j) & 1));
            }
            break;
        }
    }
    if(s.empty()) s = "0";
    memset(dp,-1,sizeof(dp));
    return solve(0,1,0);
}
