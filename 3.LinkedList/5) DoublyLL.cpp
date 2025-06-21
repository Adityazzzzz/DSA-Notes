#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back; 

    public:
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back= back1;
    }
};

int main(){
    vector<int>arr = {2,5,8,7};

    Node* y =new Node(arr[0],nullptr,nullptr);
    cout<< y->data <<endl;
}
