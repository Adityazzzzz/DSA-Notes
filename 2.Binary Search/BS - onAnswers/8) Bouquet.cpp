#include<iostream>
using namespace std;

class Solution {
public:
    bool func(vector<int>&bloomDay, int day, int m, int k) {
        int cnt = 0;
        for(int x : bloomDay) {
            if (x <= day) {
                cnt++;
                if (cnt == k) {
                    m--;
                    cnt = 0;
                }
            }
            else cnt = 0;
        }
        return m <= 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;
        while (l<=r) {
            int mid = l + (r-l)/2;
            if (func(bloomDay, mid, m, k)) {
                result = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return result;
    }
};