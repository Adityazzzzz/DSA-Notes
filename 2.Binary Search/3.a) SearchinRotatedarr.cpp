#include<iostream>
using namespace std;

// this is for only unique elements
int search(int* arr,int n,int k){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            return mid;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(arr[mid]<=k && k<=arr[high]){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return -1;
}

int search(int* arr,int n,int k){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            return mid;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){ //this much extra code only if duplicates are present
            low=low+1;
            high=high-1;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(arr[mid]<=k && k<=arr[high]){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return -1;
}


int main(){
    int n=10;
    int arr[]={1,3,4,4,5,7,7,8,8,9};

    cout<<search(arr,5,4)<<endl;
    return 0;
}



