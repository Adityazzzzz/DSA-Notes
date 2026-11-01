#include<iostream>
using namespace std;

class FenwickTree{
    vector<int>arr;
    int n;
public:
    FenwickTree(int n){
        this->n = n;
        arr.assign(n+1,0);
    }
    void update(int i,int val){
        while(i <= n){
            arr[i] += val;
            i += (i & -i);
        }
    }
    int query(int i){
        int sum = 0;
        while(i>0){
            sum += arr[i];
            i -= (i & -i);
        }
        return sum;
    }
    
    int rangeQuery(int l,int r){
        return query(r) - query(l-1);
    }
};