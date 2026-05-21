#include <iostream>
using namespace std;

int main() {
    int hA = 4, hB = 2;
    int gA = 1;
    int gB = 4;
    
    int fA = gA + hA;
    int fB = gB + hB;

    cout<<"Node A: g = "<<gA<<", h = "<<hA<<", f = "<<fA<<endl;

    cout<<"Node B: g = "<<gB<<", h = "<<hB<<", f = "<<fB<<endl;

    if(fA < fB){
        cout<<"Next node expanded = A";
    }
    else{
        cout<<"Next node expanded = B";
    }
    return 0;
}