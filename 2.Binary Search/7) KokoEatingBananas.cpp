#include<bits/stdc++.h>
using namespace std;
// retun the min integer k such that koko can eat all bananas within H hours.
int func(int *arr,int n,int hour){
    int total=0;
    for(int i=0;i<n;i++){
        total=total+ceil(arr[i]/hour);
    }
    return total;
}
int koko(int *arr,int n,int h){
    int low=1; high=*max_element(arr,arr+n);
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        int totaltime=func(arr,n,mid);
        
        if(totaltime<=h){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}

int main(){
    int n=4;
    int minhrs=8;
    int arr[]={3,4,6,11};
    cout<<koko(arr,n,minhrs)<<endl;
    return 0;
}



