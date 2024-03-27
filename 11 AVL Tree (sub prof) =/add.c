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

    addNode(root, newValue);
    printf("Tree display: ");
    treeDisplay(*root);
    printf("\n");

    COLOR_GREEN;
    printf("Success!\n");
    TEXT_RESET;
    printf("Node added\n");
    printf("Press any key to continue\n");
    getche();
}

void addNode(NODE** root, int data){

    if (!*root){
        *root = calloc(1, sizeof(NODE));
        (*root)->data = data;
        return;
    }

    NODE* newNode = calloc(1, sizeof(NODE));
    newNode->data = data;

    NODE* currentNode = *root;

    while (1){
        if (data < currentNode->data){
            if (!(currentNode->left)){
                currentNode->left = newNode;
                break;
            } else
                currentNode = currentNode->left;

        } else {
            if (!(currentNode->right)){
                currentNode->right = newNode;
                break;
            } else
                currentNode = currentNode->right;
        }
    }
}