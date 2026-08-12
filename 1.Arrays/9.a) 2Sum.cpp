#include<iostream>
using namespace std;

string 2sum(int arr[],int n ,int K;){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int rem=K-a;

        if(mpp.find(rem) != mpp.end()){               //this is a way to check if element is present in map or not
            return "yes";                              // if needed index: return {mpp[rem], i};
        }
        mpp[a]=i;                                      // to store the index of every element
    }
    return "No";                                       // return {-1,-1}
}