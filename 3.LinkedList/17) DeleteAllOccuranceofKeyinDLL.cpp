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
// Q-1 : Delete all occurances of given key
Node* deleteAllOccuranceofKey(Node* head, int key){
    if(head == NULL || head->next == NULL) return head;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
            }
            
            Node* prevNode = temp->back;
            Node* nextNode = temp->next;
            if(nextNode != NULL) prevNode->next = nextNode;
            if(prevNode != NULL) nextNode->back = prevNode;
            delete temp;
            temp = nextNode;
        }
        temp = temp->next;
    }
    else{
        temp = temp->next;
    }
    return head;
}
//----------------------------------------------------------------------------------------------



// Q-2 : Find all pairs equal to given sums
Node* findTail(Node* head){
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    return temp;
}
vector<pair<int,int>> pairsEqualtoSum(Node* head, int sum){
    vector<pair<int,int>>and;
    if(head == NULL) return ans;

    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data){
        if(left->data + right->data == sum){
            ans.push_back({left->data,right->data})
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data < k){
            left = left->next;
        }
        else{
            right = right->back;
        }
    }
    return and;
}
//--------------------------------------------------------------------------------------------------



// Q-3: Remove duplicates
Node* remoceDulpicatesinDLL(Node* head){
    Node* temp1 = head;

    while(temp1 != NULL && temp1->next != NULL){
        Node* temp2 = temp1->next;

        while(temp2 != NULL && temp2->data == temp1->data){
            Node* duplicate = temp2;
            temp2 = temp2->next;
            delete duplicate;
        }

        temp1->next = temp2;
        if(temp2 != NULL) temp2->back = temp1;

        temp1 = temp1->next;
    }
    return head;

}
int main(){
    vector<int>arr = {2,5,8,7};
    Node* head= convertArrtoDLL(arr);
}