//This linked list file will be standard Linked list structure and will have a method to reverse a linked list using recursion

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;
void Reverse(Node* p){
    // Exit condition
    if(p->next == NULL){
        head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next; // q tracks the address that the current p var has as its next node.
    q->next = p; // Since q points to the address of the node ahead of the node being reversed we can access q take its next variable and set it to be equal to p. This is a reversal.
    p->next = NULL;

}

void Insert(int data){
    // Write a insert function to insert into the linked list.
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    else{
    Node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return;
    }
    
}

void Print(struct Node* p){
    //iterative approach
    Node* temp = p;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}


int main(){
    Insert(5);
    Insert(4);
    Insert(3);
    Insert(2);
    Print(head);
    Reverse(head);
    Print(head);
}