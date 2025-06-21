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

Node* sorting(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* zeroNode = new Node(-1,nullptr);
    Node* oneNode = new Node(-1,nullptr);
    Node* twoNode = new Node(-1,nullptr);

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            zeroNode->next = temp;
            zeroNode = zeroNode->next;
        }
        else if(temp->data == 1){
            oneNode->next = temp;
            oneNode = oneNode->next;
        }
        else if(temp->data == 2){
            twoNode->next = temp;
            twoNode = twoNode->next;
        }
        temp = temp->next; 
    }

    zeroNode->next = (oneNode->next)? oneNode->next : twoNode->next
    oneNode->next = twoNode->next;
    twoNode->next = NULL;

    Node* newHead = zeroNode->next;

    delete zeroNode;
    delete oneNode;
    delete twoNode;
    return newHead;
}

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}