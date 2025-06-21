#include<iostream>
using namespace std;

// 0(N) and O(1)
int missingNo(int *arr,int n){
    int xor1=0,xor2=0;
    
    for(int i=0;i<n-1;i++){
        xor2=xor2^arr[i];
        xor1=xor1^(i+1);
    }
    xor1=xor1^n;
    return xor1^xor2;
}

// another method:  O(N) and O(1) 
//  We can total sum the sum of all elements in arr 
// w.k.t sum2= sum of n natural numbers
//  final=sum2-sum;

int main(){
    int n=5;
    int arr[]={1,2,3,5,6};
    
    cout<<missingNo(arr,n)<<endl;;
    
    
    return 0;
}