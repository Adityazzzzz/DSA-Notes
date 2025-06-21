#include<iostream>
using namespace std;

int missingKth(int *arr,int n,int k){
    int low=0,high=n-1;
//                                             _ _ 3 4 _ 6 _ _ 9
    while(low<=high){//                        1 2     5   7 8....so 3rd missing is 5
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else high=mid-1;
    }
    return low +k;  //      ******* imp ***********
}

int main(){
    int n=4;
    int k=3;
    int arr[]={3,4,6,9};
    cout<<koko(arr,n,k)<<endl;
    return 0;
}



