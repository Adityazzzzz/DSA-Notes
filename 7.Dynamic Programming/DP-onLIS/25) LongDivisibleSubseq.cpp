#include<iostream>
using namespace std;

int printlongestIncreasingSubsequence(int arr[],int n){
    vector<int>dp(n,1),hasharr(n);
    int maxi = 1;
    int lastInd = 0;

    sort(arr.begin(),arr.end()); // extra line

    for(int i = 0; i < n; i++){
        hasharr[i]=i;
        for(int prev = 0; prev < i; prev++) {
            if(arr[prev] % arr[prev]==0 && (1+dp[prev])>dp[i]){
                dp[i] = 1+dp[i];
                hasharr[i] = prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastInd==i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lastInd]);
    while(hasharr[lastInd] != lastInd){
        lastInd = hasharr[lastInd];
        temp.push_back(arr[lastInd]);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}