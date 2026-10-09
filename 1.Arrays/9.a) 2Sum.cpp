#include<iostream>
using namespace std;

string 2sum(int arr[],int n,int K){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int rem = K-a;

        if(mpp.find(rem) != mpp.end()){
            return "yes";
        }
        mpp[a]=i;
    }
    return "No";
}