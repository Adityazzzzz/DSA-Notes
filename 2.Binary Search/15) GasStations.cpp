#include<iostream>
using namespace std;

// we have given an array of positions of gas stations, 
// we have to insert K new stations between them such that (the difference b/w consecutive is maximum) ans then take minimum of all cases


/*
// tc: O(nlogn + klogn);
// sc: O(n-1);
long double gasstation(int *arr,int n,int k){//         imp to take long double bcz ans will be decimals
    vector<int>howmany(n-1,0);
    priority_queue<pair<long double,int>>pq;

    for(int i=0;i<n-1;i++){
        pr.push({arr[i+1]-arr[i],i});
    }
    for(int i=1;i<=k;i++){
        auto tp=pq.top();//took the top ele
        pq.pop();// always remove that top ele

        int index=tp.second();
        howmany[index]++;
        
        long double inidiff=arr[index+1]-arr[index];
        long double finaldiff= inidiff / (long double)(howmany[index]+1);
        pq.push({finaldiff,index});
    }

    return pq.top().first;
}
*/
//------------------------------------------------------------------------------------------------------------------------------------

int gasstation(int *arr,int dist){
    int cnt=0;
    for(int i=1;i<arr.size();i++){
        int numinbtw=((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])/dist == numinbtw*dist){
            numinbtw--;
        }
        cnt=cnt+numinbtw;
    }
    return cnt;
}

long double gasstation(int *arr,int n,int k){//         imp to take long double bcz ans will be decimals
    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++){
        high=max(high,(long double)(arr[i+1]-arr[i]));
    }

    long double diff=1e-6;
    while(high-low > diff){
        long double mid=(low+mid)/(2.0);
        int cnt=gasstation(arr,mid);
        if(cnt>k) low=mid;
        else{
            ans=high;
            high=mid;
        }
    }
    return ans;
}

int main(){
    int n=4;
    int k=3;// extra to be inserted
    int station[]={3,4,6,9};
    cout<<gasstation(book,n,k)<<endl;
    return 0;
}



