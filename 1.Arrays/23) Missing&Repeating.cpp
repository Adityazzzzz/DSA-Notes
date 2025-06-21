#include<iostream>
#include <bits/stdc++.h>
using namespace std;


// OPTIMAL SOLU 1:
// tc: O(N) and sc: O(1);
int miss&rep(int *arr,int n){
    long long Sn=(n*(n+1))/2;
    long long S2n=(n*(n+1)*(2*n+1))/6;

    long long S1=0,S2=0;
    for(int i=0;i<n;i++){
        S1=S1+arr[i];
        S2=S2+(long long)(arr[i]*arr[i]);
    }

    long long val1=S1-Sn;               //     (x-y) =..
    long long val2=S2-S2n;              // (x^2 - y^2) =..
    val2=val2/val1;
    long long x=(val1 + val2)/2;
    long long y=x-val1;
    return {(int)x , (int)y};
}

// OPTIMAL SOLU 2:------------------------------------------------------------------------
// tc: O(N) and sc: O(1);
int miss&rep(int *arr,int n){
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        xr=xr^(i+1);
    }
    int number=xr & ~(xr-1);

    int zero=0,one=0;
    for(int i=0;i<n;i++){
        if((arr[i] & number)!=0){
            one=one^arr[i];
        }
        else {
            zero=zero^arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if((i & number)!=0){
            one=one^i;
        }
        else {
            zero=zero^i;
        }
    }
    int cnt=0;
    for (i=0;i<n;i++){
        if(arr[i]==zero) cnt++;
    }
    if(cnt==2) return {zero,one};
    else return {one,zero};
}
//----------------------------------------------------------------

int main(){
    int n=6;
    int arr[]={1,1,2,3,5,6};

    cout<<miss&rep(arr,6)<<endl;;
    return 0;
}