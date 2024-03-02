#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "functions.h"

#define BOLD_TEXT printf("\e[1m")
#define COLOR_RED printf("\e[91m")
#define COLOR_GREEN printf("\e[92m")
#define COLOR_BLUE printf("\e[94m")
#define TEXT_RESET printf("\e[m")

void addNode(NODE** root, int data){

    if (!*root){
        *root = calloc(1, sizeof(NODE));
        (*root)->x = data;
        return;
    }

    NODE* newNode = calloc(1, sizeof(NODE));
    newNode->x = data;

    NODE* currentNode = *root;

    while (1){
        if (data < currentNode->x){
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
