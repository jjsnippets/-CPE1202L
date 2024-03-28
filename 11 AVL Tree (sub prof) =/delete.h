#include "add.h"

#ifndef DELETE_H
    #define DELETE_H

    void deleteMenu(NODE** root);
    int deleteNode(NODE** root, int data);

    NODE* parentOf(NODE* root, int search);

#endif