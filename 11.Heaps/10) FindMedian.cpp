#include<iostream>
using namespace std;

int signum(int a, int b) {
    if (a == b) return 0;
    return (a > b) ? 1 : -1;
}
void callMedian(vector<int> &arr,priority_queue<int> &maxi,priority_queue<int, vector<int>, greater<int>> &mini,int &median,int i) {
    switch (signum(maxi.size(), mini.size())) {
        case 0:
            if (arr[i] > median) {
                mini.push(arr[i]);
                median = mini.top();
            } else {
                maxi.push(arr[i]);
                median = maxi.top();
            }
            break;

        case 1:
            if (arr[i] > median) {
                mini.push(arr[i]);
            } else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(arr[i]);
            }
            median = (maxi.top() + mini.top()) / 2;
            break;

        case -1:
            if (arr[i] > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(arr[i]);
            } else {
                maxi.push(arr[i]);
            }
            median = (maxi.top() + mini.top()) / 2;
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n) {

    vector<int> ans;
    priority_queue<int> maxi; // max-heap (lower half)
    priority_queue<int, vector<int>, greater<int>> mini; // min-heap (upper half)
    int median = -1;

    for (int i = 0; i < n; i++) {
        callMedian(arr, maxi, mini, median, i);
        ans.push_back(median);   // store current median after each insertion
    }
    return ans;
}