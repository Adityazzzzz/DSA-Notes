#include <bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums) {
    vector<int> ans(2, INT_MAX);
    int minRange = INT_MAX;
    
    using T = tuple<int, int, int>;  
    priority_queue<T, vector<T>, greater<T>> minHeap;
    int maxVal = INT_MIN;
    
    int k = nums.size();
    for (int i = 0; i < k; i++) {
        if (!nums[i].empty()) {
            minHeap.emplace(nums[i][0], i, 0);
            maxVal = max(maxVal, nums[i][0]);
        }
    }
    
    while (minHeap.size() == k) {
        auto [minVal, listIdx, elemIdx] = minHeap.top();
        minHeap.pop();
        
        // Update smallest range
        if (maxVal-minVal < minRange) {
            minRange = maxVal - minVal;
            ans = {minVal, maxVal};
        }
        
        // Push next from same list
        if (elemIdx+1 < nums[listIdx].size()) {
            int nextVal = nums[listIdx][elemIdx+1];
            minHeap.emplace(nextVal,listIdx,elemIdx+1);
            maxVal = max(maxVal,nextVal);
        } 
        else{
            break;  
        }
    }
    
    return ans;
}
