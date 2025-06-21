#include<iostream>
using namespace std;

bool search(vector<vector<int>>&arr,int target){
    int n=arr.size();
    int m=arr[0].size();
    int low=0,high=n*m-1;

    while(low<=high){
        int mid=(low+high)/2;
        int row= mid / m;
        int col= mid % m;

        if(arr[row][col]==target) return true;
        else if(arr[row][col]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}

int main(){
    vector<vector<int>>arr={{2,3,4,9},
                            {13,16,19,20},
                            {21,22,25,30},
                        }; 

    cout<<search(arr,25)<<endl;
    return 0;
}



