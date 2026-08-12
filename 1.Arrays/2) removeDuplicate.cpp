#include<iostream>
using namespace std;

int removeduplicate(int *arr,int n){
    int i=0;
    for(int j=i;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}