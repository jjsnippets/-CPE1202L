#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int x;
    struct node* left;
    struct node* right;
} NODE;

typedef struct queue {
    NODE* current;
    NODE* next;
} QUEUE;

void displayNode(NODE* toShow);
void addNode(NODE** root, int data, int size);

void main(){

    NODE* root = calloc(1, sizeof(NODE));
    int count = 0;

    int list[] = {3, 5, 7, 1, 4, 8, 2, 6};

    addNode(&root, 3, count++);
    addNode(&root, 4, count++);
    addNode(&root, 5, count++);

    displayNode(root);
    printf("{%d}", count);

    getche();

}

void displayNode(NODE* toShow){

    printf("[%d %ld %ld %ld]\n", toShow->x, toShow, toShow->left, toShow->right);

    printf("Parent: %d\n", toShow->x);

    if (toShow->left)
        printf("\tLeft child: %d\n", toShow->left->x);
    if (toShow->right)
        printf("\tRight child: %d\n", toShow->right->x);

}

void addNode(NODE** root, int data, int size){

    printf("{%d %d}: ", data, size);
    
    NODE* newNode = calloc(1, sizeof(NODE));
    newNode->x = data;
    displayNode(newNode);

    if (!size){
        *root = newNode;
        return;
    }

    NODE* currentNode = *root;

    for (; size > 3; size >>= 1){
        (size % 2) ? (currentNode = currentNode->left) : (currentNode->right);
    }

    (size % 2) ? (currentNode->left = newNode) : (currentNode->right = newNode);
    printf("\n");

}