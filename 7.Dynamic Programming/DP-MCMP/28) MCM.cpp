#include <iostream>
using namespace std;

int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost1 = solve(arr, i, k, dp);
        int cost2 = solve(arr, k + 1, j, dp);
        int costMultiply = arr[i - 1] * arr[k] * arr[j];

        int total = cost1 + cost2 + costMultiply;

        minCost = min(minCost, total);
    }
    return dp[i][j] = minCost;
}

// tavulation ---------------------------------------------------------------------------------------------
int matrixMultiplication(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int i = 1; i < n; ++i)   dp[i][i] = 0;

    for (int length = 2; length < n; ++length) { 
        for (int i = 1; i <= n - length; ++i) {
            int j = i + length - 1;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];
}