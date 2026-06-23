#include <bits/stdc++.h>
using namespace std;

int signum(int a,int b){
    if(a == b) return 0;
    return(a > b) ? 1 : -1;
}

void callMedian(int x,
                priority_queue<int>& maxi,
                priority_queue<int,vector<int>,greater<int>>& mini,
                int& median){

    switch(signum(maxi.size(),mini.size())){

        // Both heaps have equal size
        case 0:
            if(x > median){
                mini.push(x);
                median = mini.top();
            }
            else{
                maxi.push(x);
                median = maxi.top();
            }
            break;

        // Max heap has one extra element
        case 1:
            if(x > median){
                mini.push(x);
            }
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(x);
            }

            median =(maxi.top() + mini.top()) / 2;
            break;

        // Min heap has one extra element
        case -1:
            if(x > median){
                maxi.push(mini.top());
                mini.pop();
                mini.push(x);
            }
            else{
                maxi.push(x);
            }

            median =(maxi.top() + mini.top()) / 2;
            break;
    }
}

vector<int> findMedian(vector<int>& arr,int n){
    vector<int> ans;

    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int>> mini;

    int median = 0;
    for(int i=0;i<n;i++){
        callMedian(arr[i],maxi,mini,median);
        ans.push_back(median);
    }
    return ans;
}