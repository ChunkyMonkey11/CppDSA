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

void Print(){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    Insert(5);
    Insert(2);
    Insert(3);
    Insert(1);
    Print();
}