#include<bits/stdc++.h>
using namespace std;

// ques is: i<j and a[i]> 2*a[j]

// tc: O(2nlogn)
// sc: O(1)

void merge(int *arr,int low,int mid ,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
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
}

int countpairs(int *arr,int low,int mid ,int high){
    int right=mid+1;
    int count=0;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i] > 2*arr[right]){
            right++;
        }
        count=count+(right-(mid+1));
    }
    return count;
}

int mergesort(int *arr,int low,int high){
    if(low==high) return count;

    int count=0;
    int mid=(low+high)/2;
    count=count+mergesort(arr,low,mid);
    count=count+mergesort(arr,mid+1,high);

    count=count+countpairs(arr,low,mid,high);

    merge(arr,low,mid,high);
    return count;
}



void countreverse(int *arr,int n){
    return mergesort(arr,0,n-1);
}



int main(){
    int n=5;
    int arr[]={2,3,6,8,1};
    cout<<countreverse(arr,n);
}