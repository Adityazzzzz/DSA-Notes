#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int countsubarr(int *arr,int n,int k){
    int xr=0;
    unordered_map<int,int>mpp;  
    mpp[0]=1;
    
    for(int i=0;i<n;i++){          //     x=xor^k.....k is the target number and xor is xor of i elements                                
        xr=xr^arr[i];              //     then we have to check that, Is x exist in hashmap or not......if it exists, simply add its counts

        int x=xr^k;
        count=count+mpp[x];  

        mpp[xr]++;
    } 
    return count;  
}


int main(){
    int n=10;
    int arr[]={1,2,3,4,5,6,3,2,5,6};
    cout<<countsubarr(arr,n,6)<<endl;;
    return 0;
}