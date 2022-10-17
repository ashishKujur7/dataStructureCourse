#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node * first = NULL;

bool isEmpty() {
    return (first==NULL);
}

void insertFirst(int iData) {
    struct Node *newNode = malloc(sizeof(struct Node)); // make a new node
    newNode->data = iData;
    newNode->next=first; // the new node --> old first
    first=newNode; // first --> newNode
}

int removeFirst() {
    int returnData = first->data; // the data of the node that is to be removed
    struct Node *temp = first; // the node that is about to be removed
    first = first->next; // the new first is the next node
    free(temp);
    return returnData;
}
    
void displayList() {
    struct Node *current = first;
    while(current != NULL) {
	printf("Data of the node : %d\n", current->data);
	current = current->next;
    }
    printf("\n");
}

void push(int data) { // mimic the functions of a stack
    insertFirst(data);
}

int pop() { // likewise mimic the functions of a stack
    return removeFirst();
}

void displayStack() { // display the contents of the stack
    displayList();
}

int main() {
    push(20);
    push(40);

    displayStack();

    push(60);
    push(80);

    displayStack();

    pop();
    pop();
    
    displayStack();
}
