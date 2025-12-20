#include <iostream>
using namespace std;

// Linked List: Inserting a node at beggining
struct Node{
    int data;
    struct Node* link;
};

struct Node* head; //Global Variable not defined in any function. // This acts like the front door to our list 

void Insert(int x){
    Node* temp = (Node*)malloc(sizeof(struct Node)); //Maloc returns a pointer to the starting address of the memory block. We type cast because malloc returns a void pointer but we need a pointer to node. So this casts the pointer to a Node pointer
    (*temp).data = x; //Derefrence by using *temp to allow us to access the fields of the temp node. Otherwise we wouldnt be able to access the data fields. Could also write temp->data = x; this is an alternative syntax
    temp->link = head; // Make the new nodes link pointer point to whatever head is pointing too. 
    head = temp;


}
void Print(){
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void Insert(int data, int n){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->link = NULL;
    if(n==1){//case 1 where we want to insert at the first position
        temp1->link = head; 
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i < n-2; i++){
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;


}
int main(){
    head = NULL;
    Insert(2,1); // Head -
    Insert(3,2);
    Insert(4,1);
    Insert(5,2);
    Print();
}  
