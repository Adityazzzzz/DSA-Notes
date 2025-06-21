#include<iostream>
using namespace std;

// 1) Pick a pivot and put it in its sorted arr position 
// 2) Smaller are on left ......pivot......larger on right


//O(nlogn) & sc: O(1)

int partition(int *arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quicksort(int *arr,int low,int high){
    if(low<high){
        int pidx=partition(arr,low,high);
        quicksort(arr,low,pidx-1);
        quicksort(arr,pidx+1,high);
    }
    
}

int main(){
    int n=5;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,4);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}