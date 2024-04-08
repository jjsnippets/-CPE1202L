#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "functions.h"

void deleteMenu(NODE** root, int* count){

    COLOR_BLUE;
    printf("=== DELETE A NODE ===\n");
    TEXT_RESET;

    if(!*root){
        printf("Tree display: ");
        treeDisplay(*root, -999);
        COLOR_RED;
        printf("FAILED!\n");
        TEXT_RESET;
        printf("Data not found in tree\n");
    } else {
        deleteNode(root, (*root)->data, count);
        COLOR_GREEN;
        printf("Success!\n");
        TEXT_RESET;
        printf("Node removed\n");
    }


    printf("Press any key to continue\n");
    getche();
}

void deleteNode(NODE** root, int delValue, int* size){

    treeDisplay(*root, delValue);

    if (*size == 1){
        if ((*root)->data == delValue) {
            (*size)--;
            free(*root);
            *root = NULL;
        }

        return;
    }

    NODE* toReplace = searchNode(*root, delValue); // can be replaced with *root

    NODE* toDelete = *root;
    int movement = 1;
    for (int i = *size >> 1; i > 0; movement <<= 1, i >>= 1);
    movement >>= 1;

    for (; movement > 1; movement >>= 1)
        toDelete = (*size & movement) ? (toDelete->right) : (toDelete->left);
    toReplace->data = ((*size % 2) ? toDelete->right : toDelete->left)->data;

    if (*size % 2){
        free(toDelete->right);
        toDelete->right = NULL;
    }
    else {
        free(toDelete->left);
        toDelete->left = NULL;
    }

    (*size)--;

    // sinking
    NODE* topNode = *root;

    while (1){
        treeDisplay(*root, topNode->data);
        NODE* left = topNode->left;
        NODE* right = topNode->right;

        if (!right) break;

        NODE* bottomNode = right;
        if (left) if (right->data > left->data) bottomNode = left;

        if (bottomNode->data > topNode->data) break;

        int temp = bottomNode->data;
        bottomNode->data = topNode->data;
        topNode->data = temp;

        topNode = bottomNode;
        
    }

    return;
}

NODE* searchNode(NODE* tree, int find){

    if (!tree) return NULL;
    if (tree->data == find) return tree;

    NODE* result = NULL;

    if (tree->left) result = searchNode(tree->left, find);
    if (result) return result;

    if (tree->right) result = searchNode(tree->right, find);
    return result;
}
