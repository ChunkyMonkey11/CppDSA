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
    temp->link = head;
    head = temp;


}
void Print();

int main(){
    head = NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d",&x); 
        Insert(x)
        Print();

    }
}  