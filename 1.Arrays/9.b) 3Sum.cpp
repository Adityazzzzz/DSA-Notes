#include<iostream>
using namespace std;
// BETTER SOLU: O(n^2*logn)
/*
vector<vector<int>>3sum(int n,vector<int> &arr){

    set<vector<int>>st;
    for(int i=0;i<n;i++){
        set<int>hshset;
        for(int j=i+1;j<n;j++){

            int third= -(arr[i]+arr[j]);
            if(hshset.find(third) != hshset.end()){
                vector<int>temp ={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hshset.insert(arr[j]);// imp line
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
*/

vector<vector<int>>3sum(int n,vector<int> &arr){

    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>=0 && arr[i]==arr[i-1]){
            continue;
        }
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i] + arr[j] +arr[k];
            if(sum<0){
                j++;
            }
            else if( sum>0){
                k--;
            }
            else{
                vector<int>temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;k--;

                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;  
            }
        }
    }   
}

int main(){
    int n=5;
    int arr[]={1,8,6,7,9};
    
    cout<<3sum(arr,n,17)<<endl;;
    return 0;
}