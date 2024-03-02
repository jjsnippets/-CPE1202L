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

int deleteNode(NODE** root, int data){

    char userInput;

    if (!*root) return 0;

    printf("CALLED FUNCTION\n");

    if (!searchNode(*root, data)) return 0;

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

        NODE* parentOf = searchParent(methodOne, data);
        NODE** dataTo = (parentOf->left == deleteOne) ? &(parentOf->left) : &(parentOf->right); 

        NODE* rightmost = leftOf;
        if (rightmost){
            while (rightmost->right) rightmost = rightmost->right;

                *dataTo = leftOf;
                rightmost->right = rightOf;

        } else *dataTo = rightOf;
        free(deleteOne);

        // method 2: copy right to toDelete, move left to bottom
        NODE* deleteTwo = searchNode(methodTwo, data);
        leftOf = deleteTwo->left;
        rightOf = deleteTwo->right;

        parentOf = searchParent(methodTwo, data);
        dataTo = (parentOf->left == deleteTwo) ? &(parentOf->left) : &(parentOf->right); 

        NODE* leftmost = rightOf;
        if (leftmost){
            while (leftmost->left) leftmost = leftmost->left;

                *dataTo = rightOf;
                leftmost->left = leftOf;

        } else *dataTo = leftOf;
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
    *root = (userInput == '1') ? methodOne : methodTwo; 
    return 1;
}

NODE* searchNode(NODE* tree, int find){

    if (!tree) return NULL;
    if (tree->x == find) return tree;

    return searchNode((find < tree->x) ? tree->left : tree->right, find);

}

NODE* searchParent(NODE* tree, int find){

    if (!tree) return NULL;
    if ((tree->left->x == find) || (tree->right->x == find)) return tree;

    return searchParent((find < tree->x) ? tree->left : tree->right, find);

}

NODE* treeCopy(NODE* root){
    if (!root) return NULL;

    QUEUE* line = NULL;
    NODE* result = NULL;
    enqueue(&line, root);

    while (line){

        NODE* current = dequeue(&line);
        addNode(&result, current->x);
        
        if (current->left) enqueue(&line, current->left);
        if (current->right) enqueue(&line, current->right);

    }

    return result;

}