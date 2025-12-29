/*          
    LinkedList singly:
    - Insert
    - Delete by value
    - Reverse(recursion)
    - Print
*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head; //Global var head. Accessible to all functions 

void Insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    // Case 1 inserting into empty list.
    if(head == NULL){
        head = temp;
        return;
    }
    // Case two non empty list
    Node* temp1 = head; // Temp1 points to head and will be used to iterate to end of the list.
    
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    // When the loop exits we will be at the end of the linked list.
    temp1->next = temp;
    return;
}

void Delete(int n){
    if(head == NULL){
        printf("Empty list\n");
        return;
    }

    if(head->data == n){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else{
        Node* temp1 = head;
        while(temp1->next != NULL && temp1->next->data != n){
            temp1 = temp1->next;
        }
        if(temp1->next == NULL){
            printf("Value %d not found\n", n);
            return;
        }
        Node* deleting = temp1->next;
        temp1->next = deleting->next;
        delete deleting;
        return;
    }
}

void Reverse(Node* p){
    //reverse a linked list using recursion
    // Exit condition because only the last node has next of null.
    if(p == NULL || p->next == NULL){  // Check p first!
        if(p != NULL) head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
    
}

void Print(){
    Node* temp = head;
    printf("Printing Linked List\n");
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
    return;
}



int main(){
   // Test Insert function
   Insert(5);
   Insert(2);
   Insert(3);
   Insert(7);
   Insert(1);
   
   // Test Print function
   Print();
   
   // Test Delete function
   Delete(3);
   Print();
   Delete(5);
   Print();
   
   // Test Reverse function (pass head as parameter)
   Reverse(head);
   Print();
   
   return 0;
}

