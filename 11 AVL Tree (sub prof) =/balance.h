#include "add.h"
#include "display.h"

#ifndef BALANCE_H
    #define BALANCE_H

    void balanceTree(NODE** root, LIST* checkNodes);

    NODE* rotateLeft(NODE* A, NODE* B);
    NODE* rotateRight(NODE* A, NODE* B);
    NODE** parentOf(NODE** root, NODE* child);

#endif