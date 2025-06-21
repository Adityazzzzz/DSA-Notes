#include<iostream>
using namespace std;

/*
Dutch national flag algorithm
 low 
 mid 
 high                   0      low-1  ,  low       mid-1    ,    mid         high     ,   high+1           n-1
                        |        |        |          |           |            |            |               |
 0 --> low-1            |        |        |          |           |            |            |               |
 low --> mid-1           --------          -----------            ------------              ---------------
 mid --> high            00000000          1111111111               0,1,2 's                   222222222
 high+1 --> n-1           sorted            sorted                  un-sorted                   sorted
                                                                (bss isko sort krna h)
*/

void sorted(int arr[],int n){
    int low=0, mid=0;
    int high=n-1;
    while(mid<=high){

        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }                                               
}

int main(){
    int n=12;
    int arr[]={0,1,1,0,2,0,2,2,1,1,0,2};
    
    cout<<sorted(arr,n)<<endl;;
    return 0;
}