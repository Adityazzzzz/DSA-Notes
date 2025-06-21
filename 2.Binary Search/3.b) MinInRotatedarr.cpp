#include<iostream>
using namespace std;

int searchmin(int *arr,int n){
    int low=0,high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n=10;
    int arr[]={1,3,4,4,5,7,7,8,8,9};

    cout<<search(arr,5,4)<<endl;
    return 0;
}



