#include<iostream>
using namespace std;

int f(int i,int j,string &pattern,string &text){
    if(i==0 && j==0) return true; 
    if(i==0 && j>0) return false; 

    if(j == 0 && i > 0){ 
        for(int ii = 0; ii<=i; ii++) { 
            if(pattern[ii] != '*') return false; 
        }
        return true; 
    }
    if(dp[i][j] != -1) return dp[i][j];

    if(pattern[i-1] == text[j-1] || pattern[i] == '?'){ 
        return dp[i][j] = f(i-1,j-1,pattern,text); 
    }
    if(pattern[i-1] == '*'){ 
        return dp[i][j] = f(i-1,j,pattern,text) || f(i,j-1,pattern,text); 
    }
    return dp[i][j] = false; 
}

//tabulation------------------------------------------------------------------------------------------
int wildcard(string pattern,string text){
    int n = pattern.size(); 
    int m = text.size(); 
    vector<vector<bool>> dp(n+1, vector<int>(m+1, false)); 
    dp[0][0] = true; 

    for(int j = 1; j<=m; j++) dp[0][j] = false; 


    for(int i = 1; i<=n; i++){ 
        int fl = true; 
        for(int ii = 1; ii<=i; ii++){ 
            if(pattern[ii-1] != '*'){ 
                fl = false; 
                break; 
            }
        }
        dp[i][0] = flag; 
    }

    for(int i = 1; i<=n; i++){ 
        for(int j = 1; j<=m; j++){ 
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){ 
                dp[i][j] = dp[i-1][j-1]; 
            }
            else if(pattern[i-1] == '*'){ 
                dp[i][j] = dp[i-1][j] || dp[i][j-1]; 
            }
            else dp[i][j] = false; 
        }
    } 


    return dp[n][m]; 
}
