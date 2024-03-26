#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "display.h"
#include "delete.h"
#include "formatting.h"

void deleteMenu(NODE** root){

    int delValue, isDeleted;

    COLOR_BLUE;
    printf("=== DELETE A NODE ===\n");
    TEXT_RESET;
    printf("value to delete: ");
    scanf(" %d", &delValue);
    printf("\n");

    isDeleted = deleteNode(root, delValue);
    printf("Tree display: ");
    treeMode(*root);
    printf("\n");

    if (isDeleted){
        COLOR_GREEN;
        printf("Success!\n");
        TEXT_RESET;
        printf("Node removed\n");
    } else {
        COLOR_RED;
        printf("FAILED!\n");
        TEXT_RESET;
        printf("Data not found in tree\n");
    }

    printf("Press any key to continue\n");
    getche();
}

int deleteNode(NODE** root, int data){
    if (!*root) return 0;
    if (!searchNode(*root, data)) return 0;

    char userInput;

    NODE* methodOne = treeCopy(*root);
    NODE* methodTwo = treeCopy(*root);

    if (!((*root)->left || (*root)->right)){
        free(methodOne);
        methodOne = NULL;
        free(methodTwo);
        methodTwo = NULL;

    } else {
        // method 1: copy left to toDelete, move right to bottom
        NODE* deleteOne = searchNode(methodOne, data);
        NODE* leftOf = deleteOne->left;
        NODE* rightOf = deleteOne->right;

        // if (methodOne->data != data) displayNode(searchParent(methodOne, data));
        NODE* parentOf = (methodOne->data == data) ? NULL : searchParent(methodOne, data);
        NODE** dataTo = NULL;
        if (methodOne->data == data) dataTo = &methodOne;
        else dataTo = (parentOf->left == deleteOne) ? &(parentOf->left) : &(parentOf->right);

        NODE* rightmost = leftOf;
        if (rightmost){
            while (rightmost->right) rightmost = rightmost->right;

                *dataTo = leftOf;
                rightmost->right = rightOf;

        }
        else if (rightOf) *dataTo = rightOf;
        else *dataTo = NULL;
        free(deleteOne);

        // method 2: copy right to toDelete, move left to bottom
        NODE* deleteTwo = searchNode(methodTwo, data);
        leftOf = deleteTwo->left;
        rightOf = deleteTwo->right;

        parentOf = (methodTwo->data == data) ? NULL : searchParent(methodTwo, data);
        if (methodTwo->data == data) dataTo = &methodTwo;
        else dataTo = (parentOf->left == deleteTwo) ? &(parentOf->left) : &(parentOf->right); 

        NODE* leftmost = rightOf;
        if (leftmost){
            while (leftmost->left) leftmost = leftmost->left;

                *dataTo = rightOf;
                leftmost->left = leftOf;

        }
        else if (leftOf) *dataTo = leftOf;
        else *dataTo = NULL;
        free(deleteTwo);
    }

    printf("Method 1: ");
    treeMode(methodOne);
    printf("\n");

    printf("Method 2: ");
    treeMode(methodTwo);
    printf("\n");

    printf("Which to keep [1/2]?\n");
    userInput = getche();
    printf("\n\n");
    freeTree(*root);
    *root = (userInput == '1') ? methodOne : methodTwo;
    freeTree((userInput == '1') ? methodTwo : methodOne);
    return 1;
}

NODE* searchNode(NODE* tree, int find){

    if (!tree) return NULL;
    if (tree->data == find) return tree;

    return searchNode((find < tree->data) ? tree->left : tree->right, find);

}

NODE* searchParent(NODE* tree, int find){

    if (!tree) return NULL;
    if (tree->left) if (tree->left->data == find) return tree;
    if (tree->right) if (tree->right->data == find) return tree;

    return searchParent((find < tree->data) ? tree->left : tree->right, find);

}

NODE* treeCopy(NODE* root){
    if (!root) return NULL;

    LIST* line = NULL;
    NODE* result = NULL;
    enqueue(&line, root);

    while (line){

        NODE* current = dequeue(&line);
        addNode(&result, current->data);
        
        if (current->left) enqueue(&line, current->left);
        if (current->right) enqueue(&line, current->right);

    }

    return result;

}

void freeTree(NODE* root){
    if (!root) return;

    LIST* line = NULL;
    enqueue(&line, root);

    while (line){
        NODE* toFree = dequeue(&line);
        if (toFree->left) enqueue(&line, toFree->left);
        if (toFree->right) enqueue(&line, toFree->right);
        free(toFree);
    }
}