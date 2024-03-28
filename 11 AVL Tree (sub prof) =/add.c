#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "display.h"
#include "balance.h"
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

    //balanceTree(root, checkBalance);
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

        while(traversed){
            NODE* checkBalance = pop(&traversed);
            NODE** currentNode = parentOf(root, checkBalance);
            int currentBF = treeDepth(checkBalance->right, 1) - treeDepth(checkBalance->left, 1);

            NODE* childOf;
            int nextBF;

            if (currentBF == 2){

                childOf = checkBalance->right;
                nextBF = treeDepth(childOf->right, 1) - treeDepth(childOf->left, 1);
                
                if (nextBF == -1) checkBalance->right = rotateRight(childOf, childOf->left);
                *currentNode = rotateLeft(checkBalance, checkBalance->right);

                break;
            } else if (currentBF == -2){
                childOf = checkBalance->left;
                nextBF = treeDepth(childOf->right, 1) - treeDepth(childOf->left, 1);
                
                if (nextBF == 1) checkBalance->left = rotateLeft(childOf, childOf->right);
                *currentNode = rotateRight(checkBalance, checkBalance->left);

                break;
            }
        }
    }

    return traversed;
}