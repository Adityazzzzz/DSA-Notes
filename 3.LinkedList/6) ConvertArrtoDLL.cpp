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

int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
    
    // to print 
    Node* temp = head;
    int count=0;
    while(temp){
        cout<< temp->data <<" ";
        temp=temp->next;
        count++;
    }
}