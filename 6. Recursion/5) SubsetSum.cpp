#include<iostream>
using namespace std;

void func(int index,int sum,vector<int>arr,vector<int>ans,int N){
    if(index == N){
        ans.push_back(sum);
    }
    func(index+1,sum+arr[index],arr,ans,N);
    func(index+1,sum,arr,ans,N);
}

vector<int>subsetsum(vector<int>arr,int N){
    vector<int>ans;
    func(0,0,arr,ans,N);
    sort(ans.begin(),ans.end());
    return ans;
}