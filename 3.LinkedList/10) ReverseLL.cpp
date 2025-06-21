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

Node* reverseLLusingSwaping(Node* head){
    if(head == NULL || head->next = NULL) return head;

    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front  = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* reverseLLusingRecursion(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverseLLusingRecursion( head->next )
    Node* front = head->next;

    front->next = head;
    head->next = NULL;
    return newHead;
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