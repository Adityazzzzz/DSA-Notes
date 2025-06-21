#include<iostream>
#include<string>
using namespace std;

class Parent{
public:
    Parent(){
        cout<<"Parent class"<<endl;
    }
};
class Child1: public Parent{
public:
    Child1(){
        cout<<"child class"<<endl;
    }
};
class child2: public Parent{
public:
  child2(){
    cout<<"child class"<<endl;
   }
};
class Grandchild:public Child1,public child2{
public:
   Grandchild(){
    cout<<"Grandchild class"<<endl;
   }
};

int main(){
    Grandchild c;
    return 0;
}
    // //     A
    //     /    \
    // // B       C
    //    |       |
    // // D       E
    //     \    /
    // //     F