#include <bits/stdc++.h>
using namespace std;

long long kthLargestSum(vector<int> &arr, int k) {
    int n = arr.size();
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for (int i = 1; i <= n; i++) {
        long long sum =0;
        for (int j = i; j <= n; j++) {
            sum += arr[j];
            
            if (pq.size() < k) {
                pq.push(sum);
            } 
            else if (sum > pq.top()) {
                pq.pop();
                pq.push(sum);
            }
        }
    }
    
    return pq.top();
}
