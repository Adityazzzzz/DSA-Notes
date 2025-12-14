#include <iostream>
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
            maxarea = max(maxarea, arr[ele] * (nse-pse-1))
        }
        s.push(i);
    }

    while(!s.empty()){
        int nse = n;
        int ele = s.top();s.pop();
        int pse = s.empty()? -1 : s.top();

        maxarea = max(maxarea, arr[ele] * (nse-pse-1))
    }
    return maxarea;

}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat,int n, int m) {
    int maxArea = 0;
    vector<int> height(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }

        int area = largestRectangleArea(height);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}
