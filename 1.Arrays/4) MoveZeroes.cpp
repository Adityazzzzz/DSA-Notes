#include<bits/stdc++.h>
using namespace std;

// brute solution:
// void union{
//      vector<int>temp;
//      for(i=0 -> n){
//           if(arr[i]!=0) temp.pushback(arr[i]);
//      }
//      for(i=0 -> temp.size) arr[i]=temp[i];
//      for(i=temp.size -> n) arr[i]=0;
//}

void move0toend(int *arr,int n){
    // int i=-1;
    // for(int j=0;j<n;j++){ // only one time
    //     if(arr[j]==0){
    //         i=j;
    //         break;
    //     }
    // }
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
        }        
    }
}