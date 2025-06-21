#include<iostream>
#include <bits/stdc++.h>
using namespace std;


// tc: O(row * col)

vector<vector<int>>spiralmatrix(vector<vector<int>> &arr,int n) {
    int row=arr.size();
    int col=arr[0].size();

    int left=0, right=col-1;
    int top=0, bottom= row-1;
    vector<int>ans;

    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;

        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;++
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    // input a 2D matrix 
    cout<<spiralmatrix(arr,n)<<endl;;
    return 0;
}