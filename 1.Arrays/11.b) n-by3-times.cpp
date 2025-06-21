#include<iostream>
using namespace std;


// BETTER Solu: 
/*
vector<int> majorityelement(int arr[],int n ){
    vector<int>ans;
    map<int,int>mpp;
    int mm=int(n/3) +1;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mm) ans.push_back(arr[i]);
        if(ans.size()==2) break;
    }
    return ans;
}
*/

int majorityelement(int arr[],int n ){
    int count1=0,count2=0;;
    int ele1,ele2;
    for(int i=0;i<n;i++){  // moons's voting theorem
        if(count1==0 && arr[i]!=ele2){
            count1=1;
            ele1=arr[i];
        }
        if(count2==0 && arr[i]!=ele1){
            count2=1;
            ele2=arr[i];
        }
        else if(arr[i]==ele1) count1++;
        else if(arr[i]==ele2) count2++;
        else{
            count1--;
            count2--;
        }   
    }
    vector<int>ans;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){          // to check, is really that ele occurs more than n/2
        if(arr[i]==ele1) cnt1++;
        if(arr[i]==ele2) cnt2++;
    }
    int mm=int(n/3) +1;
    if(cnt1 > mm) ans.push_back(ele1);
    if(cnt2 > mm) ans.push_back(ele2);

    return ans;
}
int main(){
    int n=10;
    int arr[]={1,1,1,1,1,1,8,6,7,9};
    
    cout<<majorityelement(arr,n)<<endl;;
    return 0;
}