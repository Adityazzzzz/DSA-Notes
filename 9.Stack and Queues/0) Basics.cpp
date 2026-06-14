#include <bits/stdc++.h>
using namespace std;

// 1. Array to Stack
class stack{
public:
    int top=-1;

    void push(int x){
        if(top >= capacity-1){
            return;
        }
        st[++top] = x;
    }
    int pop(){
        if(isEmpty()){
            return -1; 
        }
        return st[top--];
    }
    int top(){
        if(isEmpty()){
            return -1; 
        }
        return st[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};

//----------------------------------------------------------------------------------------------
// 2. Array to Queue
class q{
public:
    arr = new int[10];
    start = -1;
    end = -1;
    currSize = 0;
    maxSize = 10;

    void push(int x){
        if(currSize==maxSize) exit(1);
        
        if(end==-1) start = 0;end = 0;
        else end =(end + 1) % maxSize;
            
        arr[end] = x;
        currSize++;
    }
    int pop(){
        if(start==-1) exit(1);

        int popped = arr[start];
        if(currSize==1) start = -1; end = -1;
        else start =(start + 1) % maxSize;
        
        currSize--;
        return popped;
    }
    int peek(){
        if(start==-1) exit(1);
        return arr[start];
    }
    bool isEmpty(){
        return(currSize==0);
    }
};
