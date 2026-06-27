#include <iostream>
using namespace std;

// no of coins
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
//-------------------------------------------------------------------------------------------------

// Minimum Platforms Required
int findPlatform(vector<int>& arr,vector<int>& dep){ 
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i=0,j=0;
    int plat=0,ans=0;

    while(i < arr.size()){ 
        if(arr[i] <= dep[j]){ 
            plat++;
            ans = max(ans, plat);
            i++;
        }
        else{ 
            plat--;
            j++;
        }
    }

    return ans;
}