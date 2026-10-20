#include<iostream>
using namespace std;

int search(int *arr,int n){
    int low = 1,high = n-2;//            _ 2nd _ _ _ _ _ _ (2-last) _ 
    //                                  |                 |
    if(n==0) return arr[0];
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];

    while(low<=high){
        int mid = (low+high)/2;
    
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return arr[mid];// arr[mid-1] < arr[mid] > arr[mid+1]
        if(arr[mid]>arr[mid-1]){
            low = mid+1;
        }
        else if(arr[mid]>arr[mid+1]){
            high = mid-1;
        }
    }
    return -1;
}


