#include<iostream>
using namespace std;

// we have m = (number to bouquet to form) and k = (no. of adjacent flowers to take to make one bouquet)

int possible(int *arr,int day,int m,int k){
    int cnt=0;
    int numB=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            numB=numB+(cnt/k);
        }
    }
    numB=numB+(cnt/k);
    return numB>=m;
}
int koko(int *arr,int n,int h){
    int low=*min_element(arr,arr+n), high=*max_element(arr,arr+n);
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        
        if(possible(arr,mid,m,k)==true){
            ans=mid;
            high=mid-1
        }
        else low=mid+1;
    }
    return low;// or return ans;
}

int main(){
    int n=4;
    int minhrs=8;
    int arr[]={3,4,6,11};
    cout<<koko(arr,n,minhrs)<<endl;
    return 0;
}



