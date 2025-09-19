#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int top = 0, down = n - 1;

    while (top < down) {
        if (matrix[top][down] == 1) {
            top++;
        } 
        else {
            down--;
        }
    }

    int candidate = top;

    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;
        if (matrix[candidate][i] == 1 || matrix[i][candidate] == 0){
            return -1;
        }
    }
    return candidate;
}