#include<iostream>
using namespace std;

int f(int i,int j,string &s,string &t){
    if(i==0 && j==0) return true;
    if(i==0 && j>0) return false;
    if(j==0 && i>0){
        for(int k=0;k<=i;k++){ 
            if(s[k]!='*') return false;
        }
        return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i-1]==t[j-1] || s[i]=='?') return dp[i][j] = f(i-1,j-1,s,t);
    if(s[i-1]=='*') return dp[i][j] = f(i-1,j,s,t) || f(i,j-1,s,t);

    return dp[i][j] = false;
}

// tabulation----------------------------------------------------------------------------------------
int wildcard(string s,string t){
    int n = s.size();
    int m = t.size();
    vector<vector<bool>> dp(n+1,vector<int>(m+1,false));
    dp[0][0] = true;

    for(int j=1;j<=m;j++){
        dp[0][j] = false;
    }
    for(int i=1;i<=n;i++){ 
        bool flag = true;
        for(int k=1;k<=i;k++){ 
            if(s[k-1] != '*'){ 
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=m;j++){ 
            if(s[i-1] == t[j-1] || s[i-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if(s[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}
