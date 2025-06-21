#include<iostream>
#include<string>
using namespace std;

// 1
class Fruits{
public:
    string name;
    string color;

};

// 2
//----Constru ctor = this initialises the object---
class Rectangle{ 
public:
    int l;
    int b;
    Rectangle(){ //this is default constructor
        l=0;
        b=0;
    }

    Rectangle(int x,int y){ //this is parameterized constructor
        l=x; 
        b=y;
    }
    Rectangle( Rectangle &r){ // copy constructor-initialises an object by another existing object
        l=r.l;
        b=r.b;
        
    }

    //-----Destructor-----------
    ~Rectangle(){
        cout<<"Destructor is called"<<endl;
    }
};

int main(){
    Fruits apple;
    apple.name="apple";
    apple.color="greenish red";

    cout<<apple.name<<"-"<<apple.color<<endl;

    // another way
    Fruits *mango = new Fruits();
    mango->color="yellow";
    mango->name="mango";
    cout<<mango->name <<"-"<<mango->color<<endl;;

    //using constructor
    Rectangle *r1=new Rectangle();
    cout<<r1->l<<" "<<r1->b<<endl;
    delete r1;

    Rectangle r2(3,4);
    cout<<r2.l<<" "<<r2.b<<endl;

    Rectangle r3=r2;
    cout<<r3.l<<" "<<r3.b<<endl;
}

// Abstraction- It enables us to display only essential information while hiding unnessary detaills

// Inheritance- a class inherits properties of another class 
// 1. class child1: public Parent{}
// 2. class child2: protected Parent{}
// 3. class child3: private Parent{}

// TYPES OF INHERITANCE- 1. single inh.(A->B), 
// 2. multilevel inh.(A->B->C), 
// 3.  Multiple inh. ((A,B)->C),
// 4.Hierarchical inh.(B<--A-->C)
// 5. Hybrid inh. (combination of types of inh.)

//--------------------------------------------------------------
//Type of polymorphism: 1. Compile Time, 2. Run time

// 1. Compile Time:-- Function overload and operator overload

// 1.A) Function Overloading- defines a number of functions with same function name, they perform differently according to the arguments passed

class sum{
public:
    void add(int x,int y){
        int sum=x+y;
        cout<<sum<<endl;
    }
    void add(int x,int y,int z){
        int sum=x+y+z;                     
        cout<<sum<<endl; 
    }
};
int main(){
    sum s;
    s.add(2,3);
    s.add(2,3,4);
    return 0;
}

// 1.B) Operator Overloading:--
class complex{
public:
    int real;
    int img;

    complex(int x,int y){
        real=x;
        img=y;
    }

    complex operator+ (complex &c){
        complex ans(0,0);
        ans.real=real +c.real;
        ans.img=img +c.img;
        return ans;
    }
};
int main(){
    complex c1(1,2);
    complex c2(1,3);

    complex c3==c1+c2;// here we have written c1+c2, its means object operator will work for object which comes after it.
    cout<<c3.real<<" i"<<c3.img<<endl;
}

//2. Runtime Poly.:-- it is also by function overwriting
// -------------------------------------------------------
// Friend function - it is a function written outside the class, it can directly access the private objects of the class

class A{
private:
    int x;
public:
    A(int y){
        x=y;
    }
};

void print(A &obj){
    cout<<obj.x<<endl;
}

int main(){
    A obj(5);
    cout<<obj.x<<endl; // it will give error
    print(obj); // it will give answer

    return 0;
}