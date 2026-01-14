#include <iostream>
using namespace std;
#define dd double

struct Item {
    int value;
    int weight;
};
bool static comp(Item a, Item b) {
    dd r1 = (dd) a.value / (dd) a.weight;
    dd r2 = (dd) b.value / (dd) b.weight;
    return r1 > r2;  
}

dd fractionalKnapsack(int W, Item arr[], int n){
    sort(arr, arr + n, comp);
    int currW = 0;  
    dd ans = 0.0; 
    for (int i = 0; i < n; i++) {
        if (currW + arr[i].weight <= W){
            currW += arr[i].weight;
            ans += arr[i].value;  
        } 
        else{
            int remain = W - currW;
            ans += (arr[i].value / (dd) arr[i].weight) * (dd) remain;
            break;
        }
    }
    return ans;
}