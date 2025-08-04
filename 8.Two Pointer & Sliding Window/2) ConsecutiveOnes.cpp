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

// Longest Repeating Character Replacement
int func(string s,int k){
    int l=0,r=0,maxlen=0,maxfreq=0;
    int hash[26] = {0};

    while(r < s.size()){
        hash[s[r]-'A']++;
        maxfreq = max(maxfreq, hash[s[r]-'A']);

        if((r-l+1)-maxfreq > k){
            hash[s[l]-'A']--;
            maxfreq = 0;
            l++;
        }
        if((r-l+1)-maxfreq <= k){
            maxlen = max(maxlen,r-l+1);
        }

        r++;
    }
}