#include<iostream>
// #include <bits/stdc++.h>
using namespace std;

int maxprodsubarr(int *nums,int n){
    int n=nums.size();
    int pre=1;
    int suff=1;
    int maxi=INT_MIN;

    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre=pre*nums[i];
        suff*=nums[n-i-1];
        maxi=max(maxi, max(pre,suff));
    }
    return maxi;
}


int main(){
    int n=10;
    int arr[]={1,2,-3,4,-5,6,3,0,5,6};
    cout<<maxprodsubarr(arr,n)<<endl;;
    return 0;
}