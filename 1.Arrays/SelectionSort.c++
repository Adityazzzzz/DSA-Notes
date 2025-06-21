#include<bits/stdc++.h>
using namespace std;


void selectionsort(int arr[],int n){
    for (int i = 0; i < n - 1; i++){
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx])  min_idx = j;
        }

        if (min_idx != i) swap(arr[min_idx], arr[i]);
    }
}

int main(){
    int n=5;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}