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

Node* merge(Node* l1,Node* l2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }
    if(list1) res->child = list1;
    else res->child = list2;

    if(dummyNode->child) dummyNode->child->next = nullptr;

    return dummyNode->child;
}

Node* flatteningLL(Node* head){
    if(!head || !head->next) return head;

    Node* mergeHead = flatteningLL(head->next);
    head = merge(head, mergedHead);
    return head;
}

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}