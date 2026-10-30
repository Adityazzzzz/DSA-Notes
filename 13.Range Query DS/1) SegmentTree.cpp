#include<iostream>
using namespace std;

int arr[100005],seg[100005];
// In this segment tree, we are calculating Max Element in Range

// TC: O(N)
void build(int ind,int low,int high){
    if(low == high){
        seg[ind] = arr[low];
        return;
    }
    
    int mid = (low + high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);//backtrack
}

// TC: O(logN)
int query(int ind,int low,int high,int l,int r){
    //complete overlap
    if(l<=low && high<=r){
        return seg[ind];
    }
    //no overlap
    if(high<l || low>r){
        return INT_MIN;
    }

    //partial overlap
    int mid = (low + high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);

    return max(left,right);
}