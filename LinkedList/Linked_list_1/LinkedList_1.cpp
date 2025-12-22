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

// Delete a node from the list by value 
void Delete(int data){
    // Write code here.
    Node* temp = head;
    int value_to_delete = data;
    bool found = false;
    // Case 1 head is the node to delete.
    if (temp->data == value_to_delete){
        head = temp->next;
        delete temp;
        return;
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


// Delete a node at n-th position 
void DeleteByPosition(int n){
    // Check if list is empty
    if(head == NULL){
        cout << "List is empty, nothing to delete.\n";
        return;
    }

    // Check for invalid position
    if(n<= 0){
        cout << "Invalid position. Position must be >=1.\n";
        return;
    }

    Node* temp1 = head;
    // Case 1 where n == 1 || First node being deleted
    if(n == 1){
        head = temp1->next;
        delete temp1;
        return;
    }

    for(int i = 0; i < n -2; i++){
        temp1 = temp1->next; //Move our temp1 tracker var
        if(temp1 == NULL){
            cout << "Position " << n << " is out of bounds.\n";
        }
    }

    if(temp1->next == NULL){
        cout << "Position " << n << " is out of bounds.\n";
        return;
    }

    Node* temp2 = temp1->next; // Var to be deleted
    temp1->next = temp2->next;
    delete temp2;


}
/*    head->[2|4] ->[4| 5] - > [5 | 20] -> [20 | 0]           
            1       2           3           4   
       
            "If I want to delete node 3 I need to have my temp1 point to the n-1th node and temp2 point to nth node. 
            so temp 1 points to [4 | 5] and temp 2 points to [5 | 20] which is to be deleted. now i would need 
            "             
*/

// Todo Reverse a linked_list iterative method. 

void Reverse(){
    Node *current, *prev,*next; 
    current = head;
    prev = NULL;
    // Iterator 
    while(current != NULL){
        next = current->next; // stores the next variable of the node we are reversing before reversal(this allows us to keep track of the next nodes address after reversal)
        current->next = prev; //sets the current nodes next variable to be = to the previous nodes address.
        prev = current;// Moving the new previous node to be the address of the node that was just updated 
        current = next; // since we stored the address of the next node in the linked list we can now safely move the current node to be the next node in the linked list   
    }
    head = prev; // head now needs to point to previous because after the loop ends current will be pointing to NULL. and prev is the last node in the list. 
}







// Print out a list
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
    Print();
    Reverse();
    Print();

};