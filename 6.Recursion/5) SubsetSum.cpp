#include<iostream>
using namespace std;

// sum of all sebsets
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


// all subsets except duplicates
void func(int index,vector<int>arr,vector<int>ds,vector<vector<int>>ans,int N){
    ans.push_back(ds);

    for(int i = index;i<N;i++){
        if(i!=index && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        func(index+1,arr,ds,ans,N);
        ds.pop_back();
    }
}
vector<vector<int>>subsetseq(vector<int>arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>ds;
    func(0,arr,ds,ans,arr.size());
    return ans;
}