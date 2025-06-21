#include<bits/stdc++.h>
using namespace std;

// brute solution: using set

// vector<int> unionArr(int *arr1,int *arr2,int n){
//     set<int>st;
//     for(int i=0;i<n;i++) st.insert(arr1[i]);
//     for(int i=0;i<n;i++) st.insert(arr2[i]);

//     vector<int>temp;
//     for(auto it:st){
//         temp.push_back(it);
//     }
//     return temp;
// }


// optimal solu: 2-pointer
vector<int> unionArr(int *arr1,int *arr2,int n){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<n){
        if(arr1[i]<=arr2[j]){
            if(ans.back() != arr1[i]){
                ans.push_back(arr1[i]);              
            }
            i++;
        }
        else{
            if(ans.back() != arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n){
        if(ans.back() != arr1[i]){
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n){
        if(ans.back() != arr2[j]){
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}


// brute solu:
// void intersection{
//      vector<int>ans;
//      int vis[n]={0}        //equal to smaller array size;

//      for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//           if(arr1[i]==arr2[j] && vis[j]==0){
//               ans.pushback(arr1[i]);
//               vis[j]=i;
//               break;
//           }
//           if( arr2[j]> arr1[i]) break;
//        }
//      }
// }

vector<int> intersectionArr(int *arr1,int *arr2,int n){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<n){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

}

int main(){
    int n=5;
    int arr1[]={1,3,4,5,6};
    int arr2[]={1,1,4,4,6};
    
    unionArr(arr1,arr2,n);
    intersectionArr(arr1,arr2,n);
    
}