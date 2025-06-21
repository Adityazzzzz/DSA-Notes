#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int countsubarr(int *arr,int n,int k){
    unordered_map<int,int>mpp;
    mpp[0]=1;
    int presum=0,count=0;

    fot(int i=0;i<n;i++){
        presum+=arr[i];
        int rem=presum-k;
        count+=mpp[rem];
        mpp[presum]++;
    }
    return count;  
}


int main(){
    int n=10;
    int arr[]={1,2,3,4,5,6,3,2,5,6};
    cout<<countsubarr(arr,n,6)<<endl;;
    return 0;
}