#include<iostream>
using namespace std;

// repeatedly find minimum element and place it at beginning
//O(n^2) worst
//O(n) best

void insertionsort(int *arr,int n){
    for(int i=1;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}