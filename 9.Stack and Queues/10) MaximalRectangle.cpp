#include<iostream>
using namespace std;

int largestRectangleArea(vector<int>& arr){
    stack<int>s;
    int maxarea = INT_MIN;        
    for (int i = 0; i < arr.size(); i++) {
        while(!s.empty() && arr[i] < arr[s.top()]){
            int ele = s.top();
            s.pop();

            int nse = i;
            int pse = s.empty()? -1 : s.top();
            maxarea = max( maxarea, (arr[ele]*(nse-pse-1)) )
        }
        s.push(i);
    }
    // if any element left in stack
    while(!s.empty()){
        int nse = n;
        int ele = s.top();
        s.pop();
        int pse = s.empty()? -1 : s.top();

        maxarea = max( maxarea, (arr[ele]*(nse-pse-1)) )
    }
    return maxarea;
}

int maximalRectangle(vector<vector<char>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> height(n,0); // no need to take 2D matrix .
    int ans = 0;

    for(int i=0;i<m;i++){

        for (int j=0;j<n;j++){
            if (matrix[i][j]=='1') height[j]++;
            else height[j] = 0;
        }
        ans = max(ans, largestRectangleArea(height));
    }
}
