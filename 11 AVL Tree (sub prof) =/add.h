#ifndef ADD_H
    #define ADD_H

    typedef struct node {
        int data;
        struct node* left;
        struct node* right;
    } NODE;

    typedef struct list{
        NODE* node;
        struct list* next;
    } LIST;

    void addMenu(NODE** root);
    LIST* addNode(NODE** root, int data);

    void balanceTree(NODE** root, LIST* traversed);

#endif