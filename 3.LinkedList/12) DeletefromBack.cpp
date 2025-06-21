// Delete Nth node from the end of the LL

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

//Brute solu 
// COUNT length of LL and len-n = kth from starting
//--------------------------------------------------------------------------------------------------------------

Node* deleteNodefromEnd(Node* head, int n){
    Node* fast = head;
    Node* slow = head;

    for(int i=1;i<=n;i++){
        fast=fast->next;
    }
    if(fast == NULL) return head->next;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return head;
}

//Q-2 : delete the middle node
Node* deleteMiddleNode(Node* head){
    Node* slow = head;
    Node* fast = head;

    //skip one step for slow
    fast = fast->next->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}