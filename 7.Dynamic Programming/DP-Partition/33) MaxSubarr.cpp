#include <iostream>
using namespace std;

class Solution {
public:
    int func(int i, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int maxsum = 0;
        int maxi = 0;

        for (int ind = 1; ind <= k && i + ind <= n; ind++) {
            maxi = max(maxi, arr[i + ind - 1]);
            int sum = maxi*ind + func(i + ind, arr, k, dp);
            maxsum = max(maxsum, sum);
        }

        return dp[i] = maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return func(0, arr, k, dp);
    }
};

//tabulation -------------------------------------------------------------------------------------
int maximumSubarray(vector<int> &num, int k) {
    int n = num.size();
    vector<int> dp(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }

        dp[ind] = maxAns;
    }

    return dp[0];
}
