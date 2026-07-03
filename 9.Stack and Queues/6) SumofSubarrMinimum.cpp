#include<iostream>
using namespace std;

vector<int> getPSE(vector<int>& arr){
    int n = arr.size();
    vector<int> psee(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

vector<int> getNSE(vector<int>& arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

int sumSubarrayMins(vector<int>& arr){
    int n = arr.size();
    vector<int> psee = getPSE(arr);
    vector<int> nse = getNSE(arr);
    long long ans = 0;

    for(int i = 0; i < n; i++){
        long long left = i - psee[i];
        long long right = nse[i] - i;

        ans = ans + ((arr[i] * left % MOD) * right) % MOD;
    }
    return ans;
}