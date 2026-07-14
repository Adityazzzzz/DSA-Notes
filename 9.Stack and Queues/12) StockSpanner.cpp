#include<iostream>
using namespace std;

// tc : O(2n)
// sc : O(n)
class StockSpanner{
public:
    stack<pair<int, int>> st;
    int index;
    StockSpanner(){
        index = -1;
    }
    int next(int price){
        index++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        int ans = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});
        return ans;
    }
};