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

Node* getkthNode(Node* temp,int k){
    k = k-1;
    while(temp != NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* reverseinKgroups(Node* head,int k){
    Node* temp = head;
    Node* prevNode = NULL;

    while(temp != NULL){
        Node* kthnode = getkthNode(temp,k);
        if(kthnode == NULL){ //edge case: if kth group is smaller than k
            if(prevNode) prevNode->next = temp;
            break;
        }

        Node* nextNode = kthnode->next;
        kthnode->next = nullptr;
        reverseLL(temp); // basic reverseLL function

        if(temp == head) head = kthnode; // it means its a first group
        else prevNode->next = kthnode;

        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}