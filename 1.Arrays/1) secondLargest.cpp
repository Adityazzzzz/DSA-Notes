#include<iostream>
using namespace std;

int secondlargest(int *arr,int n){
    int maxi=INT_MIN;
    int smax=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            smax=maxi;
            maxi=arr[i];
        }
        else if(arr[i]>smax && arr[i]<maxi){
            smax=arr[i];
        }
    }
    return smax;
}

int secondsmallest(int *arr,int n){
    int mini=INT_MAX;
    int smin=INT_MAX; 
    for(int i=0;i<n;i++){
        if(arr[i]<mini){
            smin=mini;
            mini=arr[i];
        }
        else if(arr[i]<smin && arr[i]>mini){
            smin=arr[i];
        }
    }
    return smin;
}



int main(){
    int n=5;
    int arr[]={1,3,5,7,9};
    int slarge=secondlargest(arr,n);
    int ssmall=secondsmallest(arr,n);

    cout<<slarge<<" "<<ssmall<<endl;
    return 0;
}