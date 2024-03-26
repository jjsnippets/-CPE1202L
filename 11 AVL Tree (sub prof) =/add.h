#ifndef ADD_H
    #define ADD_H

    typedef struct node {
        int data;
        struct node* left;
        struct node* right;
    } NODE;

    void addMenu(NODE** root);
    void addNode(NODE** root, int data);

#endif