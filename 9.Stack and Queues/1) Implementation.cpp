#include<iostream>
using namespace std;

// 1. Implement Stack using 1 queue
class MyStack{
    queue<int>q;
public:
    MyStack(){
    }
    void push(int x){
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

//--------------------------------------------------------------------------------------------------
// 2. Implement Queue using 2 stacks - COSTLY PUSH - easy 
class Queue {
    stack<int> s1, s2;
public:
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop() {
        if (s1.empty()) {
            return;
        }
        s1.pop();
    }
    int front() {
        if (s1.empty()) return -1;
        return s1.top();
    }
    bool empty() {
        return s1.empty();
    }
};

//---------------------------------------------------------------------------------------------------
// 3. Implement Queue in O(1) / Implement Queue using 2 stacks - COSTLY POP;
class MyQueue {
    stack<int>st1;
    stack<int>st2;
public:
    MyQueue(){   
    }
    void push(int x){
        st1.push(x);
    }

    int pop(){
        while(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int top = st2.top();
        st2.pop();
        return top;
    }
    
    int peek(){
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    bool empty(){
        return st1.empty() && st2.empty();   
    }
};
