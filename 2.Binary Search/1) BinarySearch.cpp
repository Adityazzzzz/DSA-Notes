#include<iostream>
using namespace std;

int bs(int *arr,int n,int k){
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]==k) return mid;
        else if (arr[mid]<k) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
//------------------------------------------------------------------------------------------------------

void lowerbound(int *arr,int n,int k){
    int low = 0,high = n-1;                            
    int ans = k;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}

//------------------------------------------------------------------------------------------------------

void upperbound(int *arr,int n,int k){
    int low = 0,high = n-1;                            
    int ans = k;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid] > x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}