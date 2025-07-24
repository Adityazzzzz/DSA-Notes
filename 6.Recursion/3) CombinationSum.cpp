#include<iostream>
using namespace std;


// Combination Sum 1 - using subseq method
void subseq(int index,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(index == arr.size()){
        if(taregt==0){
            ans.push_back(ds);
        }
        return;
    }

    if(arr[index]<=target){
        ds.push_back(arr[index]);
        subseq(index+1,target-arr[index],arr,ans,ds);
        ds.pop_back();
    }
    subseq(index+1,target,arr,ans,ds);

}
vector<vector<int>>combination(vector<int> &arr, int target){
    vector<vector<int>>ans;
    vector<int>ds;
    subseq(0,target,arr,ans,ds);
    return ans;
}


// Combination Sum 2
void subseq(int index,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(taregt==0){
        ans.push_back(ds);
        return;
    }

    for(int i=index;i<arr.size();i++){
        
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[index]>target) break;
        ds.push_back(arr[index]);
        subseq(index+1,target-arr[index],arr,ans,ds);
        ds.pop_back();
    }

}
vector<vector<int>>combination(vector<int> &arr, int target){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>ds;
    subseq(0,target,arr,ans,ds);
    return ans;
}
