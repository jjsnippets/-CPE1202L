#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "functions.h"

void addMenu(NODE** root, int* count){

    int newValue;

    COLOR_BLUE;
    printf("=== ADD NEW NODE ===\n");
    TEXT_RESET;
    printf("Insert value to add: ");
    scanf(" %d", &newValue);
    printf("\n");

    addNode(root, newValue, count);
    printf("Tree display: ");
    treeDisplay(*root, -999);
    printf("\n");

    COLOR_GREEN;
    printf("Success!\n");
    TEXT_RESET;
    printf("Node added\n");
    printf("Press any key to continue\n");
    getche();
}

void addNode(NODE** root, int addValue, int* size){

    LIST* visitedNodes = NULL;
    NODE* newNode = calloc(1, sizeof(NODE));
    newNode->data = addValue;

    if (!(*size)++){
        *root = newNode;

    } else {
        int movement = 1;
        for (int i = *size >> 1; i > 0; movement <<= 1, i >>= 1);
        movement >>= 1;

        NODE* currentNode = *root;

        for (; movement > 1; movement >>= 1){
            push(&visitedNodes, currentNode);
            currentNode = (*size & movement) ? currentNode->right : currentNode->left;
        }

        if (*size % 2) currentNode->right = newNode;
        else currentNode->left = newNode;
        push(&visitedNodes, currentNode);
    }

    push(&visitedNodes, newNode);
    NODE* bottomNode = pop(&visitedNodes);

    while(visitedNodes){
        treeDisplay(*root, addValue);

        NODE* topNode = pop(&visitedNodes);

        if(topNode->data < bottomNode->data) break;

        int temp = topNode->data;
        topNode->data = bottomNode->data;
        bottomNode->data = temp;

        bottomNode = topNode;
    }

}

/*
======================================================
FUNCTION    : push
DESCRIPTION : push implemntation for a stack linked list
                  inserts at the head end
ARGUMENTS
    LIST** head - pointer to stack
    NODE* toAdd - node to add to stack
======================================================
*/
void push(LIST** head, NODE* toAdd){
    LIST* newHead = calloc(1, sizeof(LIST));
    newHead->node = toAdd;

    if (*head) newHead->next = *head;

    *head = newHead;
}

/*
======================================================
FUNCTION    : pop
DESCRIPTION : pop implemntation for a stack linked list
                  removes at the head end
ARGUMENTS
    LIST** head - pointer to stack

RETURNS
    NODE* - newest node that was added to stack
======================================================
*/
NODE* pop(LIST** head){
    NODE* result = (*head)->node;
    *head = (*head)->next;
    return result;
}