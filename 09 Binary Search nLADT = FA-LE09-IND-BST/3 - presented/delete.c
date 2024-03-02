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

int deleteNode(NODE** root, int data){

    if (!*root) return 0;

    printf("CALLED FUNCTION\n");

    NODE* toDelete = searchNode(*root, data);
    if (!toDelete) return 0;

    NODE* methodOne = treeCopy(*root);
    NODE* methodTwo = treeCopy(*root);

    // method 1
    




    // method 2









}

NODE* searchNode(NODE* tree, int find){

    if (!tree) return NULL;
    if (tree->x == find) return tree;

    return searchNode((find < tree->x) ? tree->left : tree->right, find);

}