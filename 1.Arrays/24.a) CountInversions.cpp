#include<bits/stdc++.h>
using namespace std;

// ques is: i<j and a[i]>a[j]

int merge(int *arr,int low,int mid ,int high){ //.......................... 3
    vector<int>temp;
    int left=low;
    int right=mid+1;
    int count=0;

    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            count= count+(mid-left+1); ////...................................... one extra line ..bss
            right++;
        }
    }
    while (left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

    return count;
}

int mergesort(int *arr,int low,int high){ //.......................... 2
    int count=0;
    if(low==high) return count;

    int mid=(low+high)/2;
    count+= mergesort(arr,low,mid);
    count+= mergesort(arr,mid+1,high);
    count+= merge(arr,low,mid,high);

    return count;
}

int countinversions(int *arr,int n){ //.......................... 1
    return mergesort(arr,0,n-1);
}

int main(){
    int n=5;
    int arr[]={2,3,6,8,1};
    cout<<countinversions(arr,n);
}