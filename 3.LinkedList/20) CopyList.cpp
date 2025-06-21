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

void insertCopyNode(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->data);

        copy->next = nextElement;
        temp->next = copy;
        temp = nextElement;
    }
}

void connectRandomPointer(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;

        if(temp->random){
            copyNode->random = temp->random->next;
        }
        else copyNode->random = nullptr;
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dn = new Node(-1);
    Node* res = dn;

    while(temp != NULL){
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dn->next;
}

Node* clone(Node* head){
    insertCopyNode(head);
    connectRandomPointer(head);

    return getDeepCopyList(head);
}


int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}