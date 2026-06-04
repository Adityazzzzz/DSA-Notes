#include<iostream>
using namespace std;

int median(vector<vector<int>>& matrix, int n, int m){
    int low = matrix[0][0];
    int high = matrix[n-1][m-1];

    int desired =(n*m+1)/2;
    while(low < high){
        int mid = low +(high-low)/2;
        int count = 0;
        
        // count no of elements <= mid
        for(int i=0;i<n;i++){
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        
        if(count < desired) low = mid + 1;
        else high = mid;
    }
    return low;
}