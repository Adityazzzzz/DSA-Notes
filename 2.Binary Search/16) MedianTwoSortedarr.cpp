#include<iostream>
using namespace std;
/*
double median(int *arr1,int* arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0,j=0;
    int n=(n1+n2);
    
    int cnt=0;
    int idx1=n/2;
    int idx2=idx1+1;

    int ele1,ele2;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(cnt==idx1) ele1=arr1[i];
            if(cnt==idx2) ele2=arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt==idx1) ele1=arr2[i];
            if(cnt==idx2) ele2=arr2[i];
            cnt++;
            j++;
        }
    }
    while(i<n1){
        if(cnt==idx1) ele1=arr1[i];
        if(cnt==idx2) ele2=arr1[i];
        cnt++;
        i++;
    }
    while(j<n2){
        if(cnt==idx1) ele1=arr2[i];
        if(cnt==idx2) ele2=arr2[i];
        cnt++;
        j++;
    }

    if(n%2==1) return ele1;
    return (double)(ele1+ele2)/2.0;  
}*/

// tc: O(log(min(n1,n2)));

double median(int *arr1,int* arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    if(n1>n2) return median(arr2,arr1);

    int low=0,high=n1;
    int left=(n1+n2+1)/2;
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
            if(n%2==1) return max(l1,l2);
            return (double)(max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high=mid-1;
        else low=mid+1;
    }
    return 0;
}
int main(){
    int arr1[]={1,2,3,5,7};
    int arr2[]={4,5,6,8};

    cout<<median(arr1,arr2)<<endl;
    return 0;
}



