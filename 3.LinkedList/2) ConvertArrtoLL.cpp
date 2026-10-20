#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
public:
    Node(int data){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrtoLL(vector<int> &arr){
    Node* head = new Node(arr[0]);  // 1
    Node* mover = head;            //2

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);   //3
        mover->next = temp;            //4
        mover = temp;
    }
    return head;
}
