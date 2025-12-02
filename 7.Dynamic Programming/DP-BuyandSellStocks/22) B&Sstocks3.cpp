#include <bits/stdc++.h>
using namespace std;

// change: add one more parameter in func for capacity=2;

class Solution {
public:
// recursive
    int f(int i,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit=0;
        if(buy) profit = max(-prices[i]+f(i+1,0,cap,prices,dp), 0+f(i+1,1,cap,prices,dp));
        else profit = max(prices[i]+f(i+1,1,cap-1,prices,dp), 0+f(i+1,0,cap-1,prices,dp));

        return dp[i][buy][cap] =  profit;
    }

// tabulation
    int maxProfit(vector<int>& prices, int n){
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if (buy == 1) {
                        dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap] ,0+dp[ind+1][1][cap]);

                    }
                    else {
                        dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1], 0+dp[ind+1][0][cap])
                    }
                }
            }
        }
        return dp[0][1][2];
    }

};
