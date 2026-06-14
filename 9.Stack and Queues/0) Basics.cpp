#include <bits/stdc++.h>
using namespace std;

// 1. Stack using Arr
class stack{
public:
    int top=-1;

    void push(int x){
        if(top >= capacity-1){
            return;
        }
        arr[++top] = x;
    }
    int pop(){
        if(isEmpty()){
            return -1; 
        }
        return arr[top--];
    }
    int top(){
        if(isEmpty()){
            return -1; 
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};

//----------------------------------------------------------------------------------------------
// 2. Queue using Arr
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

//---------------------------------------------------------------------------------------------
// 3. Stack using LL
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Stack {
    Node* top = NULL;
public:
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    void pop() {
        if(top==NULL) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    int peek() {
        if(top==NULL) return -1;
        return top->data;
    }
    bool empty() {
        return top==NULL;
    }
};

//--------------------------------------------------------------------------------------------------
// 4. Queue using LL
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class Queue {
    Node *front=NULL, *rear=NULL;
public:
    void push(int x) {
        Node* temp = new Node(x);
        if(rear==NULL){
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void pop() {
        if(front==NULL) return;
        Node* temp = front;
        front = front->next;

        if(front == NULL) rear = NULL;
        delete temp;
    }
    int peek() {
        if(front==NULL) return -1;
        return front->data;
    }
    bool empty() {
        return front==NULL;
    }
};