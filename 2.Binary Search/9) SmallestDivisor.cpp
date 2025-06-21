#include<iostream>
using namespace std;

// tc: O( log(max)* N)
int sumbyD(int *arr,int div){
    int sum=0;
    int n=arr.size();
    for(int i=0;i<arr.size();i++){
        sum+=ceil((double)arr[i] / (double)div);
    }
    return sum;
}

int smallestdivisor(int *arr,int n,int limit){

    if(n>limit) return -1;
    int low=1, high=*max_element(arr,arr+n);
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        
        if(sumbyD(arr,mid)<=limit){
            ans=mid;
            high=mid-1
        }
        else low=mid+1;
    }
    return low;// or return ans;
}

int main(){
    int n=4;
    int limit=8;
    int arr[]={3,4,6,11};
    cout<<koko(arr,n,limit)<<endl;
    return 0;
}



