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