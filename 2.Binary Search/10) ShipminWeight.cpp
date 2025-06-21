#include<iostream>
using namespace std;

// tc: O( log(sum-max+1)* N)
int func(int *arr,int cap){
    int load=0;
    int day=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+load > cap){
            day++;
            load=arr[i];
        }
        else load+=arr[i];
    }
    return day;
}

int smallestdivisor(int *arr,int n,int days){
    int low=*max_element(arr,arr+n); 
    int high=accumulate(arr,arr+n,0);

    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        int numofdays=func(arr,mid);
        if(numofdays<=days){
            ans=mid;
            high=mid-1
        }
        else low=mid+1;
    }
    return low;// or return ans;
}

int main(){
    int n=4;
    int days=8;
    int arr[]={3,4,6,11};
    cout<<koko(arr,n,days)<<endl;
    return 0;
}



