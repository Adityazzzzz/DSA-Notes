#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// BRUTE Solu:
/*
int longestSequence(int *arr,int arr){
    if(n==0) return 0;

    int longest=1,count=0;
    int least=INT_MIN;

    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]-1 == least){
            count++;
            least=arr[i];
        }
        else if(arr[i]!=least){
            count=1; // back to initial value
            least=arr[i];
        }
        longest=max(longest,count);
    }
    return longest;
}
*/
// int longestSequence(int *arr,int arr){
//     if(n==0) return 0;

//     int longest=1;
//     unordered_set<int>st;
//     for(int i=0;i<n;i++){
//         st.insert(arr[i]);   // set only inserts unique elements(only once)
//     }

//     for(auto it:st){
//         if(st.find(it-1)==st.end()){
//             int cnt =1;
//             int x=it;--------
//             while(st.find(x+1) != st.end()){
//                 x=x+1;
//                 cnt=cnt+1;
//             }
//             longest=max(longest,cnt);
//         }
//     }
//     return longest;
// }

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int cnt1 = 1;
    int cnt2 = 0;
    if(n==0) return 0;

    sort(nums.begin(), nums.end());

    for(int i = 1 ; i < n ; i++){
        if(nums[i] != nums[i-1] ){
            if(nums[i]==nums[i-1]+1) cnt1++;
            else{
                cnt2 = max(cnt1,cnt2);
                cnt1 = 1;
            }
        }       
    }
    return max(cnt1,cnt2);
}

int main(){
    int n=10;
    int arr[]={1,1,1,1,1,1,8,6,7,9};
    
    cout<<longestSequence(arr,n)<<endl;;
    return 0;
}