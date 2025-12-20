#include <iostream>
using namespace std;

// Linked list struct

struct Node{
    int data;
    Node* next;
};

// Global var head for entry of the linked list
Node* head;



// Insert at head of list
void Insert(int data){
    // Allocate memory for a new temp node var
    Node* temp = new Node(); //New node in memory currently unfilled
    temp->data = data;
    temp->next = head;
    head = temp;

};
// Insert at nth position
void Insert(int data, int n){
    // Define temp1 this will be our new node to be inserted into the list. 
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    };
    // Case 2 where n!=1
    Node* temp2 = head;
    for(int i = 0; i < n-2; i++){
        temp2 = temp2->next;
    };
    temp1->next = temp2->next;
    temp2->next = temp1;

}

// Work on deleting a node from a list.

void Delete(int data){
    // Write code here.
    Node* temp = head;
    int value_to_delete = data;
    bool found = false;
    // Case 1 head is the node to delete.
    if (temp->data == value_to_delete){
        head = temp->next;
        delete temp;
    }
    // Case 2 value to be deleted is not the head. 
    while(temp->next != NULL){
        if (temp->next->data == value_to_delete){
            Node* Removed_Node = temp->next;
            temp->next = Removed_Node->next;
            delete Removed_Node;
            found = true;
            cout << "Node with value" << " " << data << " has been deleted.\n" ;
            return; 
        }
        temp = temp->next;
    }
    if(!found){
        cout << "Value not found \n";
    }


}

void Print(){
    Node* temp = head;
    printf("List is: ");    
    while(temp!= NULL){
        printf("%d",temp->data);
        temp = temp->next;
    };
    printf("\n");
}
// Main function
int main() {
    Insert(5);
    Insert(2);
    Insert(3);
    Insert(7);
    Delete(5);
    Print();

};