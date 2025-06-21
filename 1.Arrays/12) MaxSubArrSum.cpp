include<iostream>
#include <climits> 
using namespace std;


long long maxsubArr(int arr[],int n ){
    long long sum=0,maxi=LLONG_MIN;

    for(int i=0;i<n;i++){
        // to print the subarr
        // if(sum==0) start =i;
        sum=sum+arr[i];
        if(sum>maxi){
            maxi=sum;
            // startIndex=start;
            // endIndex=i;
        }
        if(sum<0) sum=0;
    }
    // print elements for startIndex --> EndIndex
    return maxi;
}

int main(){
    int n=10;
    int arr[]={1,1,1,1,1,1,8,6,7,9};
    
    cout<<maxsubArr(arr,n)<<endl;;
    return 0;
}