#include<iostream>
using namespace std;

// recursive
bool func(int ind,int tar,vector<int>& arr){
    if(tar==0) return true;
    if(ind==0) return arr[0] == tar;

    bool notTake = func(ind-1,tar,arr);
    bool take = false;
    if(arr[ind]<=tar) take = func(ind-1,tar-arr[ind],arr);

    return take | notTake;
}

// dp
bool func(int ind,int tar,vector<int>& arr,vector<vector<int>>& dp) {
    if(tar==0) return true;
    if(ind==0) return arr[0] == tar;
    if(dp[ind][tar]!=-1) return dp[ind][tar];

    bool notTake = func(ind-1,tar,arr,dp);
    bool take = false;
    if(arr[ind]<=tar) take = func(ind-1,tar-arr[ind],arr,dp);

    return dp[ind][tar] = take | notTake;
}

bool func(int n,int k,vector<int> &arr){
    vector<bool> prev(k+1,0),cur(k+1,0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;

    for(int ind=1;ind<n;ind++){
        for(int tar=1;tar<=k;tar++){
            bool notTake = prev[tar];

            bool take = false;
            if(arr[ind] <= tar) take = prev[tar-arr[ind]];

            cur[tar] = take | notTake;
        }
        prev = cur;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr,int n){
    int totSum = 0;
    for(int i=0;i<n;i++){
        totSum += arr[i];
    }

    if(totSum%2==1) return false;
    int k = totSum/2;

    return func(n,k,arr);
}