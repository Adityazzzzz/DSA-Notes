#include<iostream>
using namespace std;
/*
pair<int,int>seach(int *arr,int n,int k){
    int lb=lower_bound(arr,arr+n,k);
    if(lb==n || arr[lb]!=k) return {-1,-1};
    return {lb,upper_case(arr,arr+n,k) -1};
}
*/

int first(int* arr,int n,int k){
    int low=0,high=n-1;
    int firstans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            firstans=mid;
            high=mid-1;
        }
        else if(arr[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return firstans;
}

int last(int* arr,int n,int k){
    int low=0,high=n-1;
    int lastans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            lastans=mid;
            low=mid+1;
        }
        else if(arr[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return lastans;
}
pair<int,int>seach(int *arr,int n,int k){
    int f=first(arr,n,k);
    if(f==-1) return {-1,-1};
    int l=last(arr,n,k);
    return {f,l};
}

int main(){
    int n=10;
    int arr[]={1,3,4,4,5,7,7,8,8,9};

    cout<<search(arr,5,4)<<endl;
    return 0;
}



