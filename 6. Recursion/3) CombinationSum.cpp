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
