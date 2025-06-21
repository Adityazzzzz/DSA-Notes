#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//   BRUTE SOLU:
/*
vector<vector<int>>mergeoverlapping(vector<vector<int>>arr,int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;

    for(int i=0;i<n;i++){
        int start=arr[i][0];   ..............1st digit of every pair
        int end=arr[i][1];     ................. 2nd digit of every pair

        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0] <= end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back;
    }
    return ans;
}
*/

// tc: O(nlogn)+O(n)
// sc: O(N)

vector<vector<int>>mergeoverlapping(vector<vector<int>>arr,int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;

    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}


int main(){
    int n=10;
    int arr[]={(1,3),(2,6),(8,10),(11,15),(9,10)};
    cout<<countsubarr(arr,n)<<endl;;
    return 0;
}