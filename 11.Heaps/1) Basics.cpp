#include <iostream>
using namespace std;

class Heap{
public:
    vector<int>arr(100);
    int size=0;
    Heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size = size + 1;
        int idx = size;
        arr[idx] = val;

        while(idx > 1){
            int parent = idx / 2;
            if(arr[parent] < arr[idx]){
                swap(arr[parent], arr[idx]);
                idx = parent;
            } 
            else {
                return;
            }
        }
    }

    void deletefromHeap() {
        if (size == 0) return;
        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while (i < size) {
            int left = 2*i;
            int right = 2*i + 1;

            if(left < size && arr[i] < arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            } 
            else if(right < size && arr[i] < arr[right]){
                swap(arr[i], arr[right]);
                i = right;
            } 
            else {
                return;
            }
        }
    }



}