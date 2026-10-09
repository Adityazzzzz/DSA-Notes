#include<iostream>
using namespace std;

// O(N/2*N/2) + O(N*N/2)
void rotatematrix(vector<int> &arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
}