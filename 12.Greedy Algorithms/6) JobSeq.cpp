#include <iostream>
using namespace std;

struct Job{
    int id,dead,profit;
};
bool cmp(Job a,Job b){
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[],int n){
    sort(arr,arr+n,cmp);
    int maxi = 0;
    
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i].dead);
    }

    vector<int> slot(maxi+1,-1);
    int cnt = 0;
    int profit = 0;

    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(slot[j] == -1){
                slot[j] = arr[i].id;
                cnt++;

                profit += arr[i].profit;
                break;
            }
        }
    }

    return {cnt,profit};
}