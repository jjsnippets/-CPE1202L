#include "add.h"

#ifndef DELETE_H
    #define DELETE_H

    void deleteMenu(NODE** root);
    int deleteNode(NODE** root, int data);

    NODE* searchNode(NODE* tree, int find);
    NODE* parentOf(NODE* root, int search);

#endif