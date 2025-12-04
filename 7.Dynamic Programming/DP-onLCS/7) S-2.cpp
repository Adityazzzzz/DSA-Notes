#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;

    for(int ind=1;ind<n;ind++) {
        for (int target=1;target<=k;target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target) take = prev[target - arr[ind]];
            cur[target] = take || notTake;
        }
        prev = cur;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr,int n) {
    int totSum = 0;
    for(int i=0;i<n;i++) totSum += arr[i];
    if(totSum%2==1) return false;
    int k = totSum/2;

    return subsetSumToK(n,k,arr);
}