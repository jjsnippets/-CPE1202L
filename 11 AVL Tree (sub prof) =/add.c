#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "display.h"
#include "formatting.h"

void addMenu(NODE** root){

    int newValue;

    COLOR_BLUE;
    printf("=== ADD NEW NODE ===\n");
    TEXT_RESET;
    printf("Insert value to add: ");
    scanf(" %d", &newValue);
    printf("\n");

    LIST* checkBalance = addNode(root, newValue);
    printf("Before balancing: ");
    treeDisplay(*root);
    printf("\n");

    balanceTree(root, checkBalance);
    printf("After balancing: ");
    treeDisplay(*root);
    printf("\n");

    COLOR_GREEN;
    printf("Success!\n");
    TEXT_RESET;
    printf("Node added\n");
    printf("Press any key to continue\n");
    getche();
}

LIST* addNode(NODE** root, int data){
    LIST* traversed = NULL;

    if (!*root){
        *root = calloc(1, sizeof(NODE));
        (*root)->data = data;

    } else {
        NODE* newNode = calloc(1, sizeof(NODE));
        newNode->data = data;

        NODE* currentNode = *root;
        NODE** nextNode = (data < currentNode->data) ? &(currentNode->left) : &(currentNode->right);
        push(&traversed, currentNode);

        while(*nextNode){
            currentNode = *nextNode;
            nextNode = (data < currentNode->data) ? &(currentNode->left) : &(currentNode->right);
            push(&traversed, currentNode);
        }

        *nextNode = newNode;
    }

    return traversed;
}

void balanceTree(NODE** root, LIST* traversed){


    
}