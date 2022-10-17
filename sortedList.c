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

void insert(int iData) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = iData;
    struct Node *previous = NULL;
    struct Node *current = first;

    while(current != NULL && iData > current->data) {
	previous = current;
	current = current->next;
    }

    if(previous == NULL) first = newNode;
    else previous->next = newNode;

    newNode->next = current;
}

struct Node* delete() {
    struct Node *temp = first;
    first = first -> next;
    return temp;
}

void displayList() {
    printf("List --- (first --> last)  \n");
    struct Node *current = first;
    while(current != NULL) {
	printf("Data : %d\n", current->data);
	current = current->next;
    }
    printf("\n");
}

int main() {
    insert(20);
    insert(40);

    displayList();

    insert(10);
    insert(30);
    insert(50);

    displayList();

    delete();

    displayList();
    return 0;
}
