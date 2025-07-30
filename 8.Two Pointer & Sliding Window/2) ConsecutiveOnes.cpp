#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int zeroes=0,maxlen=0,left=0,right=0;

    while(right<n){
        if(nums[right]==0){
            zeroes++;
        }
        if(zeroes<=k){
            maxlen = max(maxlen,right-left+1);
        }
        if(zeroes>k){
            if(nums[left]==0) zeroes--;
            left++;
        }
        right++;
    }
    return maxlen;
}


// Fruit and baskets
// similar appoach like above ques

int fruitbasket(vector<int>& fruits) {
    int n = fruits.size();
    int maxlen=0,left=0,right=0;
    map<int,int>mpp;

    while(right<n){
        mpp[fruits[right]]++;

        if(mpp.sizze()>k){
            mpp[fruits[left]]--;
            if(mpp[fruits[left]]==0) mpp.erase(mpp[fruits[left]]);
            left++;
        }
        if(mpp.size()<=k) maxlen = max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}
