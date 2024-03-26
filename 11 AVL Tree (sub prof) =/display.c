#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "display.h"
#include "formatting.h"

void traversalMenu(NODE** root){

    COLOR_BLUE;
    printf("=== TRAVERSE TREE ===\n");
    TEXT_RESET;

    printf("Breadth-first: ");
    breadthFirst(root);
    printf("\n");

    printf("Depth-first Inorder Traversal: ");
    inOrder(*root, 1);
    printf("\n");

    printf("Depth-first Preorder Traversal: ");
    preOrder(*root, 1);
    printf("\n");

    printf("Depth-first Postorder Traversal: ");
    postOrder(*root, 1);
    printf("\n");

    printf("Tree display: ");
    treeMode(*root);
    printf("\n");
    printf("Press any key to continue\n");
    getche();
}

void breadthFirst(NODE** root){
    if (!*root) return;

    LIST* bft = NULL;
    NODE* toPrint = NULL;
    enqueue(&bft, *root);

    while (bft){

        toPrint = dequeue(&bft);
        if (toPrint->left) enqueue(&bft, toPrint->left);
        if (toPrint->right) enqueue(&bft, toPrint->right);
        printf("%d ", toPrint->data);
    }
}

void inOrder(NODE* root, int depth){
    if (!root) return;

    inOrder(root->left, depth + 1);
    printf("%d ", root->data);
    inOrder(root->right, depth + 1);
}

void preOrder(NODE* root, int depth){
    if (!root) return;

    printf("%d ", root->data);
    preOrder(root->left, depth + 1);
    preOrder(root->right, depth + 1);
}

void postOrder(NODE* root, int depth){
    if (!root) return;

    postOrder(root->left, depth + 1);
    postOrder(root->right, depth + 1);
    printf("%d ", root->data);
}

void treeDisplay(NODE* root){
    if (!root) return;

    int maxDepth = treeDepth(root, 1);

    for (int i = 0; i < maxDepth; i++) printf("\n");
    MOVE_UP(maxDepth);
    showLeaves(root, 1);
    MOVE_DOWN(maxDepth);
    printf("\n");

}

int treeDepth(NODE* root, int depth){
    if (!root) return depth - 1;

    int dLeft = treeDepth(root->left, depth + 1);
    int dRight = treeDepth(root->right, depth + 1);

    return (dLeft > dRight) ? dLeft : dRight;
}

void showLeaves(NODE* root, int depth){
    if (!root) return;

    showLeaves(root->left, depth + 1);
    MOVE_DOWN(depth);
    printf("[%3d]", root->data, depth);
    MOVE_UP(depth);
    MOVE_LEFT(1);
    showLeaves(root->right, depth + 1);
}

void enqueue(LIST** head, NODE* toAdd){

    if (!*head){
        *head = calloc(1, sizeof(LIST));
        (*head)->node = toAdd;
        return;
    }

    LIST* lastQueue = *head;
    LIST* insert = calloc(1, sizeof(LIST));
    insert->node = toAdd;

    while (lastQueue->next) lastQueue = lastQueue->next;
    lastQueue->next = insert;

}

NODE* dequeue(LIST** head){

    NODE* result = calloc(1, sizeof(NODE));
    result = (*head)->node;

    LIST* newHead = ((*head)->next) ? (*head)->next : NULL;

    *head = newHead;
    return result;

}
