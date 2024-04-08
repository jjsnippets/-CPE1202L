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

    NODE* newNode = calloc(1, sizeof(NODE));
    newNode->data = addValue;

    if (!(*size)++){
        *root = newNode;
        return;
    }

    int movement = 1;
    for (int i = *size >> 1; i > 0; movement <<= 1, i >>= 1);
    movement >>= 1;

    NODE* currentNode = *root;

    for (; movement > 1; movement >>= 1)
        currentNode = (*size & movement) ? currentNode->right : currentNode->left;

    if (*size % 2) currentNode->right = newNode;
    else currentNode->left = newNode;
}
