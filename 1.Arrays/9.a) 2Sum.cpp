#include<iostream>
using namespace std;


string 2sum(int arr[],int n ,int K;){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int a= arr[i];
        int more=K-a;

        if(mpp.find(more) != mpp.end()){               //this is a way to check if element is present in map or not
            return "yes";                              // if needed index: return {mpp[more], i};
        }
        mpp[a]=i;                                      // to store the index of every element
    }
    return "No";                                       // return {-1,-1}
}
 

int main(){
    int n=5;
    int arr[]={1,8,6,7,9};
    
    cout<<2sum(arr,n,17)<<endl;;
    return 0;
}