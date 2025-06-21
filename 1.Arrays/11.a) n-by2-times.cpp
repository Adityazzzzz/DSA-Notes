#include<iostream>
using namespace std;


int majorityelement(int arr[],int n ){
    int count=0;
    int ele;
    for(int i=0;i<n;i++){  // moons's voting theorem
        if(count==0){
            count=1;
            ele=arr[i];
        }
        else if(arr[i]==ele) count++;
        else count--;
    }

    int count2=0;
    for(int i=0;i<n;i++){          // to check, is really that ele occurs more than n/2
        if(arr[i]==ele) count2++;
    }
    if(count2 > n/2) return ele;

    return -1;
}

int main(){
    int n=10;
    int arr[]={1,1,1,1,1,1,8,6,7,9};
    
    cout<<majorityelement(arr,n)<<endl;;
    return 0;
}