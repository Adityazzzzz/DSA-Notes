#include<iostream>
using namespace std;

//convert arr to heap

// implemented max-heap
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<n && arr[largest]<arr[left]) largest = left;
    if(right<n && arr[largest]<arr[right]) largest = right;

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

//------------------------------------------------------------------------------------
//Heap sort

void heapsort(vector<int>&arr,int n){
    while(n>1){
        swap(arr[n],arr[1]);
        n--;
        heapify(arr,n,1);
    }
}