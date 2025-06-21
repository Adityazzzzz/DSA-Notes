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
//--------------------------------------------------------------------------------------------------





// add +1 to a LL
int addHelp(Node* temp){
    if(temp == NULL) return 1;

    int carry = addHelp(temp->next);
    temp->data += carry;
    if(temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}
Node* adding(Node* head){
    int carry = addHelp(head);
    if(carry == 1){
        Node* newNode = new Node(1,nullptr);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
//-------------------------------------------------------------------------------------------------




// Add two LL
Node* addingtwoLL(Node* num1,Node* num2){
    Node* dummyNode = new Node(-1,nullptr);
    Node* temp = dummyNode;
    Node* t1 = num1;
    Node* t2 = num2;    
    int carry = 0;

    while(t1!=NULL || t2!=NULL){
        int sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;
        Node* newNode = new Node(sum%10,nullptr);
        carry = sum/10;

        temp->next =  newNode;
        temp = temp->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry,nullptr);
        temp->next =  newNode;
    }
    return dummyNode->next;
}


int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}