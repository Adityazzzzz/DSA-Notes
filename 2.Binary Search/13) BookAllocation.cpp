#include<iostream>
using namespace std;

// we have to give n books to m students.(n>m) and FIND THAT MAX NO. OF PAGES IS MIN(ex: sum of any 2books should be min)
int func(int *book,int mid,int k){
    int stu=0,bookpages=0;
    for(int i=0;i<book.size();i++){
        if(bookpages+book[i]<=mid){
            bookpages=bookpages+book[i];
        }
        else{
            stu++;
            bookpages=book[i];
        }
    }
    return stu;
}

int bookall(int *book,int n,int students){
    int low=*max_element(book,book+n);
    int high= accumulate(book,book+n,0);
    if(students>n) return -1;
    while(low<=high){
        int mid=(low+high)/2;
        int noofstu=func(book,mid,students);
        if(noofstu > students){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}

int main(){
    int n=4;
    int student=3;
    int book[]={3,4,6,9};
    cout<<bookall(book,n,student)<<endl;
    return 0;
}



