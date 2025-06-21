#include<iostream>
#include<vector>
using namespace std ;

// when we are given row and column : n and r ,respectively.
// O(n) and O(1)
int combination(int x,int y){   // x=n-1 & y=r-1;
    int ans=1;
    for(int i=0;i<y;i++){
        ans=ans*(x-i);
        ans=ans/(i+1);
    }
    return ans;
}

// when we have to print full row
// O(n) and O(1)
vector<vector<int>>row(int n){  
    int ans=1;
    vector<int>ansrow;
    ansrow.push_back(1);
    for(int i=1;i<n;i++){
        ans=ans*(n-i);
        ans=ans/(i);
        ansrow.push_back(ans);
    }
    return ansrow;   
}

// when we have to print full pascal triangle when rows are given
vector<vector<int>>pascalTri(int n){
    vector<int>ans;
    for(int i=1;i<=n;i++){
        ans.push_back(row(i));
    }
    return ans;   
}

int main(){
    int n=10;
    int r=3;
    cout<<combination(n-1,r-1)<<endl;;
    return 0;
}