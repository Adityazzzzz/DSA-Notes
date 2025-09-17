#include<bits/stdc++.h>
using namespace std;


int func(vector<int>& arr){
    stack<int>s;
    int maxarea = INT_MIN;        
    for (int i = 0; i < arr.size(); i++) {
        while(!s.empty() && arr[i] < arr[s.top()]){
            int ele = s.top();
            s.pop();

            int nse = i;
            int pse = s.empty()? -1 : s.top();
            maxarea = max(maxarea, arr[ele] * (nse-pse-1))
        }
        s.push(i);
    }

    // if any element left in stack
    while(!s.empty()){
        int nse = n;
        int ele = s.top();s.pop();
        int pse = s.empty()? -1 : s.top();

        maxarea = max(maxarea, arr[ele] * (nse-pse-1))
    }
    return maxarea;

}