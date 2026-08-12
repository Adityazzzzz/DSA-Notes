#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// better solu:   O(N + (N/2+1))  and O(N/2+1)

// int onlyonce(int *arr,int n){
//     unordered_map<long long,int>mpp;
//     for(int i=0;i<n;i++){
//         mpp[arr[i]]++;
//     }
//     for(auto it:mpp){
//         if(it.second==1) return it.first;
//     }
// }

int onlyonce(int *arr,int n){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
    }
    return xor1;
}