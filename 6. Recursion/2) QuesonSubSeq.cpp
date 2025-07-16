#include<iostream>
using namespace std;

void subseq(int index,vector<int>&ds,int sum,int target,int arr[],int n){
    if(index == n){
        if(sum==target){
            for(auto it:ds) cout<<it<<" ";
        }
        return;
    }
    // when pick
    ds.push_back(arr[index]);
    sum += arr[index];
    subseq(index+1,ds,sum,target,arr,n);

    //not pick
    sum -= arr[index];
    ds.pop_back();
    subseq(index+1,ds,sum,target,arr,n);
}



// Technique for returning only one ans
bool subseq(int index,vector<int>&ds,int sum,int target,int arr[],int n){
    if(index == n){
        if(sum==target){
            for(auto it:ds) cout<<it<<" ";
            return true;
        }
        else return false;
    }
    // when pick
    ds.push_back(arr[index]);
    sum += arr[index];
    if (subseq(index+1,ds,sum,target,arr,n) == true) return true;

    //not pick
    sum -= arr[index];
    ds.pop_back();
    if (subseq(index+1,ds,sum,target,arr,n) == true) return true;

    return false;
}