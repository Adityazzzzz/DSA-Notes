#include<iostream>
using namespace std;

int bs(int *arr,int n,int k){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==k) return mid;
        else if (arr[mid]<k) low=mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    int n=5;
    int arr[]={1,3,5,7,9};

    cout<<bs(arr,5,1)<<endl;
    return 0;
}
//------------------------------------------------------------------------------------------------------

void lowerbound(int *arr,int n,int k){ //           lb=lower_bound(arr.begin(),arr.end(),n)
    int low=0,high=n-1;                            
    int ans=k;//                              to get index: lower_bound(arr.begin(),arr.end(),n) - arr.begin()
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid] >= x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

//------------------------------------------------------------------------------------------------------

void upperbound(int *arr,int n,int k){ //           ub= upper_bound(arr.begin(),arr.end(),n)
    int low=0,high=n-1;                            
    int ans=k;//                              to get index: upper_bound(arr.begin(),arr.end(),n) - arr.begin()
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid] > x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}