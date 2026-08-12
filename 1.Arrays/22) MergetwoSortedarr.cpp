#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//  OPTIMAL SOLU 1:  tc: O(min(n,m)) + O(nlogn) +O(mlogm)
// sc: O(1)

// void merge(int *arr1,int *arr2,int n,int m){
//     int left=n-1;
//     int right=0;      //                             (_ _ _ _ )    (_ _ _ _ _)
//     while(left>=0 && right<m){        //                    |       |
//         if(arr1[left]>arr2[right]){//                        left    right
//             swap(arr1[left],arr2[right]);
//             left--;
//             right++;
//         }
//         else break;
//     }
//     sort(arr1,arr1+n);
//     sort(arr2,arr2+m);
//}
void merge(int* nums1,int* nums2,int m,int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
        
    while(j>=0){
        if(i>=0 && nums1[i]>nums2[j]){
            nums1[k--] = nums1[i--];
        } 
        else{
            nums1[k--] = nums2[j--];
        }
    }
}