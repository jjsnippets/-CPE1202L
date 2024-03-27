#include "add.h"

#ifndef DISPLAY_H
    #define DISPLAY_H

    typedef struct list{
        NODE* node;
        struct list* next;
    } LIST;

    void push(LIST** root, NODE* toAdd);
    LIST* pop(LIST** root);

    void enqueue(LIST** root, NODE* toAdd);
    NODE* dequeue(LIST** root);


    void displayMenu(NODE* root);

    void breadthFirst(NODE* root);
    void inOrder(NODE* root);
    void preOrder(NODE* root);
    void postOrder(NODE* root);
    void treeDisplay(NODE* root);

    void showLeaves(NODE* root, int depth);
    int treeDepth(NODE* root, int depth);

#endif