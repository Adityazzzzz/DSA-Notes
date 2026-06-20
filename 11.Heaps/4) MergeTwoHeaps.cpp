#include<iostream>
using namespace std;

void heapify(vector<int> &arr,int n,int i){
    int largest = i;
    int left  = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest]) largest = left;
    if(right<n && arr[right]>arr[largest]) largest = right;

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

vector<int> mergeHeaps(const vector<int> &a,const vector<int> &b){
    vector<int>ans;
    ans.reserve(a.size() + b.size());

    // copy all elements
    ans.insert(ans.end(),a.begin(),a.end());
    ans.insert(ans.end(),b.begin(),b.end());

    int n = ans.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(ans,n,i);
    }
    return ans;
}
