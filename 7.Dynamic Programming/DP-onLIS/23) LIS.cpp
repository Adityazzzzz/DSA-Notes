#include<iostream>
using namespace std;

// longest length
int f(ind ind,int prevInd, int arr[],int n, vector<vector<int>>&dp){
    if(ind==m) return 0;
    if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];

    int len = 0 + f(i+1,prevInd,arr,n);
    if(prevInd==-1 || arr[ind]>arr[prevInd]) len = max(len, 1+f(ind+1,ind,arr,n));  

    return dp[ind][prevInd+1]=len;
}
// tabulation
int lis(int arr[],int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prevInd = ind-1;prevInd>=-1;prevInd--){
            int len = 0 + dp[i+1][prevInd+1];
            if(prevInd==-1 || arr[ind]>arr[prevInd]) len = max(len, 1+dp[ind+1][ind+1]);

            dp[ind][prevInd+1] = len;
        }
    }
    return dp[0][-1+1];
}


// print LIS
// its TLE but needed to print 
int longestIncreasingSubsequence(int arr[], int n){
    vector<int> dp(n, 1);
    int maxi = 1;
    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(arr[prev] < arr[i]) {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int printlongestIncreasingSubsequence(int arr[],int n){
    vector<int>dp(n,1);
    int maxi = 1;
    int lastInd = 0;

    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(arr[prev] < arr[i] && (1+dp[prev])>dp[i]){
                dp[i] = 1+dp[i];
                has[i] = prev;
            }
        }
        
        if(dp[i]>maxi){
            maxi=dp[i];
            lastInd==i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lastInd]);
    while(hash[lastInd] != lastInd){
        lastInd = hash[lastInd];
        temp.push_back(arr[lastInd]);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}