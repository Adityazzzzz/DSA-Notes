#include<iostream>
using namespace std;
// same as previous ques, bss here we have to find kth rather than median from two arrays.

double median(int *arr1,int* arr2,int k){
    int n1=arr1.size();
    int n2=arr2.size();
    if(n1>n2) return median(arr2,arr1,k);

    int low=max(0,k-n2),high=min(k,n1);//         ***imp

    int left=k;
    int n=n1+n2;

    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=n-mid1;

        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;

        if(mid1<n1) r1=arr1[mid1];
        if(mid2<n2) r2=arr2[mid2];
        if(mid1-1>=0) l1=arr1[mid1-1];
        if(mid2-1>=0) l2=arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
           return max(l1,l2);   
        }
        else if(l1>r2) high=mid-1;
        else low=mid+1;
    }
    return 0;
}
int main(){
    int arr1[]={1,2,3,5,7};
    int arr2[]={4,5,6,8};

    cout<<median(arr1,arr2, 4)<<endl;
    return 0;
}



