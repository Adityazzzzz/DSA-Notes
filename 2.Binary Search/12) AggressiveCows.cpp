// At starting we done basic BS 
// then we did, BS on answers: where we have to find min/max

// Now we will do BS, where we have to find  (min->max) / (max->min)
//-----------------------------------------------------------------------------------------------------------------
#include<iostream>
using namespace std;

// Aggressive cows: find the, (min dist btw the cows) is max

bool possible4cows(int *arr,int dist,int cows){
    int cntcows=1,last=arr[0];

    for(int i=0;i<arr.size();i++){
        if(arr[i]-last>=dist){
            cntcows++;
            last=arr[i];
        }
        if(cntcows>cows) return true;
    }
    return false;
}
int aggcows(int *arr,int n,int cows){
    sort(arr,arr+n);
    int low=1,high= arr[n-1]-arr[0];// max-min
    while(low<=high){
        int mid=(low+high)/2;
        if(possible4cows(arr,mid,cows)==true){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}


int main(){
    int n=4;
    int cows=3;
    int arr[]={3,4,6,9};
    cout<<aggcows(arr,n,cows)<<endl;
    return 0;
}



