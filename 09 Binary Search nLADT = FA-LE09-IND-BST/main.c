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
    NODE* data;
    struct queue* next;
} QUEUE;

void displayNode(NODE* toShow);

void addNode(NODE** root, int data, int* count);


void main(){

    NODE* root = calloc(1, sizeof(NODE));
    int count = 0;

    // [6, 2, 11, 7, 3, 12, 8, 4]
    // for (int i = 0; i < 8; i++){
    //     printf("[%d %d] ", i, ((i+5)*295) % 13);
    // }

    addNode(&root, 6, &count);

    displayNode(root);

}

void displayNode(NODE* toShow){

    // debug
    printf("[%d %ld %ld %ld]\n", toShow->x, toShow, toShow->left, toShow->right);

    printf("Parent: %d\n", toShow->x);

    if (toShow->left)
        printf("\tLeft child: %d\n", toShow->left->x);
    if (toShow->right)
        printf("\tRight child: %d\n", toShow->right->x);

    printf("\n");

}

void addNode(NODE** root, int data, int* count){

    NODE* newNode = calloc(1, sizeof(NODE));
    newNode->x = data;

    if (!(*count)++){
        *root = newNode;
        return;
    }

    // NODE* currentNode = *root;

    // if (currentNode->x < data)

    



}