#include <bits/stdc++.h>
using namespace std;

// tc : O(2n)
// sc : O(n)
class StockSpanner{
    stack<pair<int,int>>st;
    int index = -1;

    StockSpanner(){
        index = -1;
        st.clear();
    }
    int next(int val){
        index = index + 1;
        while(!st.empty() && st.top()<=val){
            st.pop();
        }

        ans = index - (st.empty() ? -1 : st.top().second)
        st.({val,index});
        return ans;
    }
}