// Implement Stack using 1 queue

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



// Implement Queue in O(1);
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
