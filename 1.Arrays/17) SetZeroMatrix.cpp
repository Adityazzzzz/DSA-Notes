#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// BRUTE Solu:  tc:  O(n^2) + O(n+n) + O(n^2)
/*
void markRow(i)
    for(j=0->n)
        if(arr[i][j]!=0) arr[i][j]=-1

void markColumn(j)
    for(i=0->n)
        if(arr[i][j]!=0) arr[i][j]=-1

for(i=0 -> n)
    for(j=0->n)
        if(arr[i][j] == 0)
            markRow(i);
            markColumn(j);
}
for(i=0 -> n)
    for(j=0->n)
        if(arr[i][j] == -1) arr[i][j]=0;         
}
*/


// BETTER SOLU:   tc: O(2*n*n)  sc:O(n+n)
/*
int row[]={0}, int col[]={0}
for(i=0 -> n)
    for(j=0->n)
        if(arr[i][j] == 0)
            row[i]=1; ...marked
            col[j]=1; ...marked
}
for(i=0 -> n)
    for(j=0->n)
        if(row[i]==1 || col[j]==1) arr[i][j]=0;         
}
*/


// O(n+m)
vector<vector<int>>zeromatrix(vector<vector<int>> &matrix,int n){
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){

                matrix[i][0]=0;
                if(j!=0) matrix[0][j]==0;
                else col0=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]!=0){
                if(matrix[0][j]==0 ||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0) {
        for(int j=0;j<n;j++) matrix[0][j]=0;
    }
    if(col0==0){
        for(int i=0;i<n;i++) matrix[i][0]=0;
    }
}



int main(){
    // input a 2D matrix 
    cout<<zeromatrix(arr,n)<<endl;;
    return 0;
}