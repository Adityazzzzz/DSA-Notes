/*
solu-1: put of data of DLL in a stack and then put it back in DLL , 
because of LIFO , it reverses

O(2N) and O(N)
*/

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

Node* reverseDLL(Node* head){
    if(head == NULL || head->next = NULL) return head;
    
    Node* prev = NULL;
    Node* temp = head;
    while(temp != NULL){
        prev = temp->back;       // 1
        temp->back = temp->next; // 2
        temp->next = prev;

        temp = temp->back;  // 3
    }
    return prev->back;
    // O(N) and O(1)
}

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
    Node* temp  = reverseDLL(head);
    int count=0;
    while(temp){
        cout<< temp->data <<" ";
        temp=temp->next;
        count++;
    }
}