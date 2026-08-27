#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& arr){
        int mini = INT_MAX;
        int maxp = 0;
        for(int it:arr){
            mini = min(mini,it);
            maxp = max(maxp,it-mini);
        }
        return maxp;
    }
};