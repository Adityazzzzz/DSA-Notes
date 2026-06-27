#include <iostream>
using namespace std;

long long solve(vector<int>& bt){
    sort(bt.begin(), bt.end());
    long long wait = 0;
    long long curr = 0;
    for(int x:bt){
        wait += curr;
        curr += x;
    }
    return wait / bt.size();
}