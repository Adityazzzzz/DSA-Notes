#include<iostream>
#include <bits/stdc++.h>
using namespace std;


// O(N/2 * N/2) + O(N*N/2)
void rotatematrix(vector<int> &arr,int n){
    for(int i=0;i<n-1;i++){ // till second last ele
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
}

int main(){
    // input a 2D matrix 
    cout<<rotatematrix(arr,n)<<endl;;
    return 0;
}