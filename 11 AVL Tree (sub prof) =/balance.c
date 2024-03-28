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
            NODE* checkBalance = pop(&checkNodes);
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
