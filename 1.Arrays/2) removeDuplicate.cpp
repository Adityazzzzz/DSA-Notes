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

int main(){
    int n=6;
    int arr[]={1,1,3,5,7,9};
    
    N=removeduplicate(arr,n);
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}