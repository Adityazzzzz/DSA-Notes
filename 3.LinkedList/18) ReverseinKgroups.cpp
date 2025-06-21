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

Node* reverseinKgroups(Node* head){
    Node* temp = head;
    Node* prevNode = NULL;
    Node* nextNode = NULL;

    while(temp != NULL){
        
    }
}

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}