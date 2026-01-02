#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays) {
    vector<int> result;
    using T = tuple<int, int, int>; 
    priority_queue<T, vector<T>, greater<T>> minHeap;
    
    int k = arrays.size();
    for(int i = 0; i < k; i++){
        if(!arrays[i].empty()){
            minHeap.emplace(arrays[i][0], i, 0);
        }
    }
    
    while (!minHeap.empty()) {
        auto [val, arrIdx, elemIdx] = minHeap.top();
        minHeap.pop();
        
        result.push_back(val);

        if(elemIdx+1 < arrays[arrIdx].size()){
            int nextVal = arrays[arrIdx][elemIdx + 1];
            minHeap.emplace(nextVal, arrIdx, elemIdx + 1);
        }
    }
    
    return result;
}
