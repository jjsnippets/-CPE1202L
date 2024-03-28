#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "display.h"
#include "balance.h"
#include "formatting.h"

#include "zdebug.h"

void balanceTree(NODE** root, LIST* checkNodes){
    if (checkNodes){
        while(checkNodes){
            NODE* currentNode = pop(&checkNodes);
            printNode(currentNode);
        }
    }
}

NODE* rotateLeft(NODE* A, NODE* B){
    // NODE* innerTree = B->left;
    A->right = B->left;
    B->left = A;
    return B;
}

NODE* rotateRight(NODE* A, NODE* B){
    // NODE* innerTree = B->right;
    A->left = B->right;
    B->right = A;
    return B;
}

NODE** parentOf(NODE** root, NODE* child){

    if(child->data == (*root)->data)
        return root;
    else if(child->data < (*root)->data)
        return parentOf(&((*root)->left), child);
    else
        return parentOf(&((*root)->right), child);

}
