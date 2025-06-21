// find the intersecting node in LL
/*
    1 -> 2 -> 3 
               \
                a -> b -> c
               / 
    1 -> 2 -> 3

    ans = a
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

Node* findIntersection(Node* head){
    if(head1 == NULL || head2 == NULL) return NULL;

    Node* t1 = head1;
    Node* t2 = head2;

    while(t1!=t2){
        t1 = t1->next;
        t2 = t2->next;

        if(t1==t2) return t1;

        if(t1==NULL) t1 = head2;
        if(t2==NULL) t2 = head1;

    }
    return t1;
}


int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}