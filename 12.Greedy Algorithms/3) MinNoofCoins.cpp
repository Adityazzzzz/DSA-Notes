#include <iostream>
using namespace std;

vector<int>minPartition(int N){
    vector<int>coins ={2000,500,200,100,50,20,10,5,2,1};
    vector<int>ans;

    for(int it:coins){
        while(N >= it){
            ans.push_back(it);
            N -= it;
        }
    }
    return ans;
}