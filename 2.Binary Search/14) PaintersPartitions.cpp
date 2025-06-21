#include<iostream>
using namespace std;

// painter's partition: min of(max of all cases)
// This problem is also known as: Split array in k subarr, where max of subarr sum is min

// both have same solu as Books Allocation

int main(){
    int n=4;
    int student=3;
    int book[]={3,4,6,9};
    cout<<bookall(book,n,student)<<endl;
    return 0;
}



