#include<iostream>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(const vector<int> &a, const vector<int> &b) {
    vector<int> merged;
    merged.reserve(a.size() + b.size());

    // copy all elements
    merged.insert(merged.end(), a.begin(), a.end());
    merged.insert(merged.end(), b.begin(), b.end());

    int n = merged.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(merged, n, i);
    }
    return merged;
}
