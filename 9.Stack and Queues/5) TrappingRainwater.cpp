#include<iostream>
using namespace std;

// tc : O(3n)
// sc : O(2n)
int trap(vector<int>& arr){
    int n = arr.size();
    vector<int> pref(n), suff(n);

    pref[0] = arr[0];
    for(int i=1;i<n;i++){
        pref[i] = max(pref[i-1],arr[i]);
    }

    suff[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suff[i] = max(suff[i+1],arr[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int water = min(pref[i],suff[i]) - arr[i];
        ans += water;
    }
    return ans;
}
//---------------------------------------------------------------------------------------------------

// MOST OPTIMAL CODE - Interview
// tc : O(n)
// sc : O(1)

int trap(vector<int>& arr){
    int n=arr.size();
    int l=0, r=n-1;
    int leftMax=0, rightMax=0;
    int ans = 0;

    while(l<r){
        if(arr[l] <= arr[r]){
            if(arr[l] >= leftMax) leftMax = arr[l];
            else ans += leftMax - arr[l];

            l++;
        }
        else{
            if(arr[r] >= rightMax) rightMax = arr[r];
            else ans += rightMax - arr[r];

            r--;
        }
    }
    return ans;
}