#include<iostream>
#include <climits> 
using namespace std;

// BRUTE Solu: 
/* O( n! * n);   

step1- generate all permutations using recursion
step 2- linear search
step 3- find just next to it
*/


void nextPermutation(vector<int> &arr,int n){
    int idx=-1;
    for(int i=n-2;i>=0;i--){ // from second last element
        if(arr[i]<arr[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1) reverse(arr.begin(),arr.end());
    for(int i=n-1;i>idx;i--){ // from last element
        if(arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }
    reverse(arr.begin()+idx,arr.end());
}


int main(){
    int n=10;
    int arr[]={1,1,1,1,1,1,8,6,7,9};
    
    cout<<nextPermutation(arr,n)<<endl;;
    return 0;
}