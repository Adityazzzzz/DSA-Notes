#include<iostream>
using namespace std;

int countsubarr(int *arr,int n,int k){
    int xr = 0;
    unordered_map<int,int>mpp;  
    mpp[0] = 1;
    
    for(int i=0;i<n;i++){      
        xr = xr^arr[i];
        int x = xr^k;
        count = count+mpp[x];  
        mpp[xr]++;
    } 
    return count;  
}