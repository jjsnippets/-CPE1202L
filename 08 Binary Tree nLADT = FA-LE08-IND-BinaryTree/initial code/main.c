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
    struct queue* next;
} QUEUE;

void displayNode(NODE* toShow);
void displayAll(NODE* root, int size);

void enqueue(QUEUE** head, NODE* toAdd);
NODE* dequeue(QUEUE** head);

void addNode(NODE** root, int data, int size);

void main(){

    NODE* root = calloc(1, sizeof(NODE));
    int count = 0;

    int list[] = {3, 5, 7, 1, 4, 8, 2, 6};

    for (int i = 1; i < 9; i++)
        addNode(&root, i, count++);

    displayAll(root, count);

    printf("Successfully ran!");

}

void displayNode(NODE* toShow){

    // debug
    // printf("[%d %ld %ld %ld]\n", toShow->x, toShow, toShow->left, toShow->right);

    printf("Parent: %d\n", toShow->x);

    if (toShow->left)
        printf("\tLeft child: %d\n", toShow->left->x);
    if (toShow->right)
        printf("\tRight child: %d\n", toShow->right->x);

    printf("\n");

}

void displayAll(NODE* root, int size){

    if (!size) return;
    
    QUEUE* bft = calloc(1, sizeof(QUEUE));
    NODE* display;
    enqueue(&bft, root);

    while(size--){

        display = dequeue(&bft);
        displayNode(display);
        
        if (display->left) enqueue(&bft, display->left);
        if (display->right) enqueue(&bft, display->right);

    }
    free(bft);
}

void enqueue(QUEUE** head, NODE* toAdd){

    if (!(*head)->current){
        (*head)->current = toAdd;
        return;
    }

    QUEUE* lastQueue = *head;
    QUEUE* insertEnd = calloc(1, sizeof(QUEUE));
    insertEnd->current = toAdd;

    while (lastQueue->next)
        lastQueue = lastQueue->next;

    lastQueue->next = insertEnd;

}

NODE* dequeue(QUEUE** head){

    NODE* result = calloc(1, sizeof(NODE));
    result = (*head)->current;

    QUEUE* newHead = (*head)->next ? (*head)->next : calloc(1, sizeof(QUEUE));

    (*head) = newHead;
    return result;
}

void addNode(NODE** root, int data, int size){

    int movement = 1;
    for (int i = (size+1) >> 1; i > 0; movement <<= 1, i >>= 1);
    movement >>= 1;
    
    NODE* newNode = calloc(1, sizeof(NODE));
    newNode->x = data;

    if (!size){
        *root = newNode;
        return;
    }

    NODE* currentNode = *root;

    for (; movement > 1; movement >>= 1){

        if ((size+1) & movement){
            (currentNode = currentNode->right);
        } else {
            (currentNode = currentNode->left);
        }
    }

    if (size % 2){
            (currentNode->left = newNode);
    } else {
            (currentNode->right = newNode);
    } 
}