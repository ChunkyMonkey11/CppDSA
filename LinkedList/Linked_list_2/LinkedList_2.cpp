#include <iostream>
using namespace std;

// Linked List: Inserting a node at beggining
struct Node{
    int data;
    struct Node* next;
};



void ReversePrint(struct Node* p){
    // Try to print recursively. 
    if (p == NULL) return; // exit condition 
    ReversePrint(p->next);
    printf("%d", p->data);
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



Node* Insert(Node* head, int data){
    Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        Node* temp1 = head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}



int main(){
    struct Node* head = NULL; //Local variable head defined using c style programming.
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    Print(head);
    ReversePrint(head);
    

}  
