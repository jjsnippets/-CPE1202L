#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "display.h"
#include "formatting.h"

#include "zdebug.h"

void displayMenu(NODE* root){

    COLOR_BLUE;
    printf("=== TRAVERSE TREE ===\n");
    TEXT_RESET;

    printf("Breadth-first: ");
    breadthFirst(root);
    printf("\n");

    printf("Depth-first Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Depth-first Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Depth-first Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    printf("Tree display: ");
    treeDisplay(root, -999);
    printf("\n");

    balanceDisplay(root);

    printf("Press any key to continue\n");
    getche();
}

void breadthFirst(NODE* root){
    if (root){
        LIST* bft = NULL;
        NODE* toPrint = NULL;
        enqueue(&bft, root);

        while (bft){
            toPrint = dequeue(&bft);
            if (toPrint->left) enqueue(&bft, toPrint->left);
            if (toPrint->right) enqueue(&bft, toPrint->right);
            printf("%d ", toPrint->data);
        }
    }
}

void inOrder(NODE* root){
    if (root){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(NODE* root){
    if (root){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(NODE* root){
    if (root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void treeDisplay(NODE* root, int match){
    if (root){
        int maxDepth = treeDepth(root, 1);

        for (int i = 0; i < maxDepth; i++) printf("\n");
        MOVE_UP(maxDepth);
        showLeaves(root, 1, match);
        MOVE_DOWN(maxDepth);
        printf("\n");
    }
}

int treeDepth(NODE* root, int depth){
    int result;

    if (!root)
        result = depth - 1;

    else{
        int dLeft = treeDepth(root->left, depth + 1);
        int dRight = treeDepth(root->right, depth + 1);
        result = (dLeft > dRight) ? dLeft : dRight;
    }

    return result;
}

void showLeaves(NODE* root, int depth, int match){
    if (root){
        showLeaves(root->left, depth + 1, match);
        MOVE_DOWN(depth);
        if (root->data == match) COLOR_GREEN;
        printf("[%3d]", root->data, depth);
        if (root->data == match) TEXT_RESET;
        MOVE_UP(depth);
        MOVE_LEFT(1);
        showLeaves(root->right, depth + 1, match);
    }
}

void enqueue(LIST** head, NODE* toAdd){
    if (!*head){
        *head = calloc(1, sizeof(LIST));
        (*head)->node = toAdd;

    } else {
        LIST* lastQueue = *head;
        LIST* insert = calloc(1, sizeof(LIST));
        insert->node = toAdd;

        while (lastQueue->next) lastQueue = lastQueue->next;
        lastQueue->next = insert;
    }
}

NODE* dequeue(LIST** head){

    NODE* result = calloc(1, sizeof(NODE));
    result = (*head)->node;

    LIST* newHead = ((*head)->next) ? (*head)->next : NULL;

    *head = newHead;
    return result;

}

void push(LIST** root, NODE* toAdd){
    LIST* newHead = calloc(1, sizeof(LIST));
    newHead->node = toAdd;

    if (*root) newHead->next = *root;

    *root = newHead;
}

NODE* pop(LIST** root){
    NODE* result = (*root)->node;
    *root = (*root)->next;
    return result;
}
