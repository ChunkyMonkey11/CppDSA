#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* head;
// Define an insert function to insert into this doubly linked list. 
void Insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    Node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;

    return;
}

void Delete(int n){
    // Case 1 empty list
    if(head == NULL){
        printf("Can't delete from an empty list\n");
        return;
    }
    // Case 2  Only one node in list and head is the node to be deleted. 
    if(head->data == n && head->next == NULL){
        Node* temp = head;
        head = NULL;
        delete temp;
        return;
    }

    // Case 3 head is the node to delete and there is a node in front of it. 
    if(head->data == n && head->next != NULL){
        Node* temp = head; 
        temp->next->prev = NULL;
        head = temp->next;
        delete temp;
        return;
    }
    //Case 4 head is not the node to be deleted and we need to iterate over the list. 
    Node* temp1 = head;
    while(temp1->next != NULL && temp1->next->data != n){
        temp1 = temp1->next;
    }
    if (temp1->next == NULL){
        printf("%d could not be found\n", n);
        return;
    }
    else{
        Node* deleting = temp1->next;
        if(deleting->next == NULL){
            temp1->next = NULL;
            delete deleting;
            return;
        }
        else{
            temp1->next = deleting->next;
            deleting->next->prev = temp1;
            delete deleting;
            return;
        }
        
    }
    

}
void Print(){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void Reverse(){
    // Case 1:(Empty list or one node list)
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* prevNode = NULL;
    Node* currNode = head;
    while(currNode != NULL){
        prevNode = currNode->prev;
        currNode->prev = currNode->next;
        currNode->next = prevNode;
        // [0|1|2] Swaps and becomes [2|1|0] prevNode holds value of 0 | currNodes previous pointer swaps with the node ahead| and the currNodes next value gets swapped with the stored previous value in prevNode
        prevNode = currNode; // Save current node before moving (this will be the new head after loop)
        currNode = currNode->prev;
     }
    head = prevNode; // Update head to point to the new head (last node processed)
    return;

}


int main(){
    Insert(5);
    Insert(2);
    Insert(3);
    Insert(1);
    Print();
    Reverse();
    Print();
}