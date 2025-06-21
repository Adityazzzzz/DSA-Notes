#include<iostream>
#include <climits> 
using namespace std;


// long long rearragnebySIGN(int arr[],int n ){
//     int pos[n/2],neg[n/2];
//     pos[]=all positive elements;
//     neg[]=all negative elements;

//     now put them alternatingly in arr: by relative even index with pos[] and odd index with neg[]

//     for the remaining elements at the end;
// }


int main(){
    int n=10;
    int arr[]={1,1,1,1,1,1,8,6,7,9};
    
    cout<<rearragnebySIGN(arr,n)<<endl;;
    return 0;
}