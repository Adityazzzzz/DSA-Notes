#include<iostream>
using namespace std;

vector<int> getPSEE(vector<int>& a){
    int n = a.size();
    vector<int> p(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()] > a[i])
            st.pop();
        p[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return p;
}

vector<int> getNSE(vector<int>& a){
    int n = a.size();
    vector<int> p(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();

        p[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return p;
}

vector<int> getPGEE(vector<int>& a){
    int n = a.size();
    vector<int> p(n);        
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()] < a[i])
            st.pop();
        p[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return p;
}

vector<int> getNGE(vector<int>& a){
    int n = a.size();
    vector<int> p(n);        
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()] <= a[i])
            st.pop();

        p[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return p;
}

long long sumSubarrayRanges(vector<int>& nums){
    int n = nums.size();
    auto psee = getPSEE(nums);
    auto nse = getNSE(nums);        
    auto pgee = getPGEE(nums);
    auto nge = getNGE(nums);

    long long mn = 0, mx = 0;

    for(int i=0;i<n;i++){
    long long left = i - psee[i];
        long long right = nse[i] - i;
        
        mn += 1LL * nums[i] * left * right;
    }

    for(int i=0;i<n;i++){
        long long left = i - pgee[i];
        long long right = nge[i] - i;

        mx += 1LL * nums[i] * left * right;
    }

    return mx - mn;
}