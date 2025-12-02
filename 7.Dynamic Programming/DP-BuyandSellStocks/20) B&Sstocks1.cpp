#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices){
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int it : prices) {
            minPrice = min(minPrice, it);
            maxProfit = max(maxProfit, it - minPrice);
        }
        return maxProfit;
    }
};