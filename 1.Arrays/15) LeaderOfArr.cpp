#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>leaderofarr(int *arr,int arr){
    vector<int>ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi) ans.push_back(arr[i]);
        maxi=max(maxi,arr[i]);
    }
    // sort or reverse ans vector acc to ques
}