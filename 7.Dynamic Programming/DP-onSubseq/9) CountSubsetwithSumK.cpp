#include<iostream>
using namespcae std

int f(int ind,int sum,vector<int> &arr){
    if(sum == 0) return 1;
    if(ind == 0) return (arr[0]==sum);
    if(dp[ind,sum] != -1) return dp[ind][sum];

    int notpick = f(ind-1,sum,arr);
    int pick = 0;
    if(arr[ind] <= sum) pick = f(ind-1,sum-arr[ind],arr);

    return dp[ind][sum] = notpick + pick;
}

// tabulation --------------------------------------------------------------------------------------
int f(vector<int> &arr,int tar){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0))

    for(int i=0;i<n-1;i++) dp[i][0] = 1;
    if(arr[0]<=tar) dp[0][arr[0]] = 1;

    for(int ind=1;ind<n-1;ind++){
        for(int sum=0;sum<=tar;sum++){
            int notpick = dp[ind-1][sum];
            int pick = 0;
            if(arr[ind] <= sum) pick = dp[ind-1][sum-arr[ind]];

            dp[ind][sum] = pick + notpick;

        }
    }
    
    return dp[n-1][tar];
}


// space optimization -----------------------------------------------------------------------------------
int f(vector<int> &arr,int tar){
    int n = arr.size();
    vector<int>prev(tar+1,0);
    vector<int>curr(tar+1);
    prev[0] = 1;
    curr[0] = 1;

    if(arr[0] <= tar) prev[arr[0]] = 1;

    for(int ind=1;ind<n-1;ind++){
        for(int sum=0;sum<=tar;sum++){
            int notpick = prev[sum];
            int pick = 0;
            if(arr[ind] <= sum) pick = prev[sum-arr[ind]];

            curr[sum] = pick + notpick;
        }
        prev = curr;
    }
    
    return prev[tar];
}




// new concept
// above are only working when every element is >= 1

// in case of zero: {0,0,1}

int f(int ind,int sum,vector<int> &arr){
    if(ind==0){
        if(sum==0 && arr[0]) return 2;
        if(sum==0 || sum==arr[0]) return 1;
        return 0;
    }

    if(dp[ind,sum] != -1) return dp[ind][sum];
    int notpick = f(ind-1,sum,arr);
    int pick = 0;
    if(arr[ind] <= sum) pick = f(ind-1,sum-arr[ind],arr);

    return dp[ind][sum] = notpick + pick;
}