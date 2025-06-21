#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// BRUTE solu: O(N^3)

// int longestSubArr(int *arr,int n){
//     for(i=0 ->n){
//         for(j=0 -> n){
//             for(k=i -> j){
//                 sum+=arr[i];
//                 if(sum==k) maxl=max(maxl,j-i+1);
//             }
//         }
//     }
//     return maxl;
// }
//------------------------------------------------------------------------------------------------------------------------------------

// BETTER solu: applicable for both when arr contains zeroes or negatives

// O( n * logn) .. logn because we use map
// O(n)
/*
int longestSubArr(vector<long long> *arr,long long n){
    map<long long,int>mpp;
    long long sum=0;
    int maxl=0;

    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];
        if(sum==k){
            maxl=max(maxl,i+1);
        }
        long long remaining=sum-k;

        if(mpp.find(remaining) == mpp.end()){
            mpp[sum] =i;
        }
        else if(mpp.find(remaining) != mpp.end()){
            int length=i-mpp[remaining];
            maxl=max(maxl,length);
        }
        
    }
    return maxl;
}
*/

// Using 2 pointer  ~~ sliding window

// O(2N) && 0(1)
int longestSubArr(vector<long long> &arr,long long n,long long k){
    int left=0,right=0;
    int sum=0;
    long long maxl=0;

    while(right<n){
        sum=sum+arr[right];
        
        while(sum>k && left<=right){
            sum=sum-arr[left];
            left++;
        }
        right++;
        
        if(sum==k) maxl=max ( maxl, (long long)right-left+1 );
    }
    return maxl; 
}

int main(){
    long long n=9;
    vector<long long> arr={1,1,2,2,3,3,5,6,6};
    
    cout<<longestSubArr(arr,n,6)<<endl;;

    return 0;
}