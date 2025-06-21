#include<iostream>
using namespace std;

// These are binar search on 2d arrays;
int firstocc(int* arr,int n,int k){
    int low=0,high=n-1;
    int firstans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            firstans=mid;
            high=mid-1;
        }
        else if(arr[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return firstans;
}

int findrow(vector<vector<int>> &arr,int n,int m){
    int cnt_max=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int cnt_ones=m-firstocc(arr,m,1);
        if(cnt_ones>cnt_max){
            cnt_max=ant_ones;
            index=i;
        }
    }
    return index;
}

int main(){
    vector<vector<int>>arr={{0,0,0,1,1},
                            {0,0,0,0,0},
                            {0,1,1,1,1},
                            {0,0,0,0,1},
                            {0,1,1,1,1}
                        }; 

    cout<<findrow(arr,5,5)<<endl;
    return 0;
}



