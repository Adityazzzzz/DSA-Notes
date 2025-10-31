#include<iostream>
using namespace std;

int f(int i,intj,string &s1,string &s2,vector<vector<int>> &dp){
    if( i < 0) return j+1; 
    if( j < 0) return i+1; 
    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i] == s2[j]) return f(i-1,j-1,s1,s2,dp); 
    return dp[i][j] = 1 + min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp))); 
}
// same code after shifting
int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    if(i==0) return j; 
    if(j==0) return i; 
    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i-1] == s2[j-1]) return f(i-1,j-1,s1,s2,dp); 
    return dp[i][j] = 1 + min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp))); 
}


