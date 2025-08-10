#include<iostream>
using namespace std;

// climbing stairs
int solve(int n,vector<int> &dp){
    if(n<=2) return n;
    if(dp[n]!=-1) return dp[n]; 
        
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}
int climbStairs(int n) {.
    vector<int> dp(n+1,-1);
    return solve(n,dp);
}

int climbStairs(int n) {
    if (n <= 2) return n;

    int prev1 = 2;
    int prev2 = 1;
    int cur = 0;
    for (int i = 3; i < n; i++) {
        cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return cur;        
}

// ------------------------------------------------------------------------------

//  Frog jump
// recursive 
int f(int index, vector<int>&height){
    if(index==0) return 0;

    int left = f(index-1,height) + abs(height[index] - heigh[index-1]);
    int right = INT_MAX;
    if(index>1) right = f(index-2,height) + abs(height[index] - heigh[index-2]);

    return min(left,right);
}
// recursive to dp
int f(int index, vector<int>&height,vector<int>&dp){
    if(index==0) return 0;
    if(dp[index]!=-1) return dp[index];

    int left = f(index-1,height,dp) + abs(height[index] - heigh[index-1]);
    int right = INT_MAX;
    if(index>1) right = f(index-2,height,dp) + abs(height[index] - heigh[index-2]);

    return dp[index] = min(left,right);
}
// dp to tabular
int f(int index){
    vector<int>dp(n,0);
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int l = dp[i-1] + abs(height[i] - heigh[i-1]);
        if(i>1) r = dp[i-2] + abs(height[i] - heigh[i-1]);

        dp[i] = min(l,r);
    }
    return dp[n-1];
}
// space optimization
int f(int index){
    // vector<int>dp(n,0);
    prev1 = 0;
    prev2 = 0;
    for(int i=1;i<n;i++){
        int l = prev1 + abs(height[i] - heigh[i-1]);
        if(i>1) r = prev2 + abs(height[i] - heigh[i-1]);

        int curr = min(l,r);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


//----------------------------------------------------------------------------------------------

// Maximum sum of non-adjacent element
//recursion
func(int index){
    if(index==0) return arr[index];
    if(index<0) return 0;

    int pick = arr[index] + func(index-2);
    int notpick = 0 + func(index-1);

    return max(pick,notpick);
}
// recursion to dp
func(int index,vector<int>&dp){
    if(index==0) return arr[index];
    if(index<0) return 0;
    if(dp[index] != -1) return dp[index];

    int pick = arr[index] + func(index-2);
    int notpick = 0 + func(index-1);

    return dp[index] = max(pick,notpick);
}
// dp to tabulation
func(int index){
    vector<int>dp;
    dp[0] = arr[0];
    for(int i=1;i<n;i++){
        int pick = arr[index] + dp[n-2];
        int notpick = 0 + dp[n-1];

        dp[i] = max(pic,notpick);
    }
    return dp[n-1];
}
// space optimization
func(int index){
    // vector<int>dp;
    int prev = arr[0];
    int prev2 = 0;

    for(int i=1;i<n;i++){
        int pick = arr[i]
        if(pick>1) pick+=prev2;
        int notpick = 0 + prev;

        int curr = max(pic,notpick);
        prev2 = prev;
        prev = curr
    }
    return prev;
}
//----------------------------------------------------------------------------------------------


// House Robber
// same as above ques - but here houses are in circle 
func(int index){
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int pick = arr[i]
        if(pick>1) pick+=prev2;
        int notpick = 0 + prev;

        int curr = max(pic,notpick);
        prev2 = prev;
        prev = curr
    }
    return prev;
}

long long houseRobber(vector<int>&houses){
    vector<int>temp1;
    vector<int>temp2;
    int n = houses.size();
    if(n==1) return houses[0];

    for(int i=0;i<n;i++){
        // fill element
        if(i!=0) temp1.push_back(houses[i]); // except first ele
        if(i!=n-1) temp2.push_back(houses[i]);// except second ele
    }
    return max(func(temp1),func(temp2));
}
