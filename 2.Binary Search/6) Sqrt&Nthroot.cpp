#include<iostream>
using namespace std;

int sqrt(int n){
    int low=1,high=n;
    while(low<=high){
        int mid=(low+high)/2;
        long long val=mid*mid;

        if(val<=n) low=mid+1;
        else high=low-1;   
    }
    return high; 
}
//----------------------------------------------------------------------------------------------
int func(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}

int nthroot(int n,int m){
    int low=1,high=m;
    while(low<=high){
        int mid=(low+high)/2;
        // long long val=pow(mid,n)....overflow ho jayega
        long long val=func(mid,n,m);

        if(val==1) return mid;
        else if(val==0) low=mid+1;
        else high=mid-1;   
    }
    return -1; 
}

int main(){
    int n=11;
    cout<<sqrt(n)<<endl;
    cout<<nthroot(n)<<endl;
    return 0;
}



