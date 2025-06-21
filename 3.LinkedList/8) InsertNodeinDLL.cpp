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

Node* convertArrtoDL(vector<int> &arr){
    Node* head = new Node(arr[0],nullptr,nullptr);
    Node* prev = head;

    for(int i=1;i<arr.length();i++){
        Node* temp = new Node(arr[0],nullptr,prev);
        prev->next =  temp;
        prev=temp;
    }
    return head;
}

Node* InsertatHead(Node* head, int val){
    Node* newNode = new Node(val,head,nullptr);
    head->back = newNode; 
    return newNode;
}

Node* InsertBeforeTail(Node* head, int val){
    if(head->next == NULL){
        return InsertatHead(head,val)
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* InsertBeforeKthNode(Node* head,int k, int val){
    if(k==1){
        return InsertatHead(head,val)
    }
    Node* temp = head;
    int cnt=0;
    while(temp!= NULL){
        cnt++;
        if(cnt==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}



int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
    
}