#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "display.h"
#include "balance.h"
#include "search.h"
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

    NODE* isPresent = searchNode(*root, delValue);
    printf("Tree display: ");
    treeDisplay(*root, delValue);
    printf("\n");

    if (!isPresent){
        COLOR_RED;
        printf("FAILED!\n");
        TEXT_RESET;
        printf("Data not found in tree\n");
        printf("\n");

    } else {
        COLOR_GREEN;
        printf("Success!\n");
        TEXT_RESET;
        printf("Node removed\n");
        printf("\n");

        LIST* checkBalance = deleteNode(root, delValue);

        printf("Before balancing: ");
        treeDisplay(*root, -999);
        printf("\n");

        balanceTree(root, checkBalance);
        printf("After balancing: ");
        treeDisplay(*root, -999);
        printf("\n");
    }

    printf("Press any key to continue\n");
    getche();
}

LIST* deleteNode(NODE** root, int data){

    LIST* traversed = NULL;
    NODE* toDelete = *root;

    while(toDelete->data != data){
        push(&traversed, toDelete);
        toDelete = (toDelete->data > data) ? toDelete->left : toDelete->right;
    }

    NODE** parentNode = parentOf(root, toDelete);
    NODE* toReplace = toDelete->right;

    if(toReplace){
        while(toReplace->left)
            toReplace = toReplace->left;
        
        toReplace->left = toDelete->left;

        NODE** prune = parentOf(root, toReplace);
        *prune = NULL;

        NODE* reconnect = toReplace;
        while(reconnect->right)
            reconnect = reconnect->right;
    
        reconnect->right = toDelete->right;

        *parentNode = toReplace;

    } else 
        *parentNode = toDelete->left;

    if(*parentNode){
        push(&traversed, *parentNode);
        if((*parentNode)->right) push(&traversed, (*parentNode)->right);
    }

    

    return traversed;
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