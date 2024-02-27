#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int x;
    struct node* left;
    struct node* right;
} NODE;

void displayNode(NODE* toShow);

void main(){

    NODE* root = calloc(1, sizeof(NODE));
    int count = 0;

    int list[] = {3, 5, 7, 1, 4, 8, 2, 6};

    root->x = 5;

    displayNode(root);


}

void displayNode(NODE* toShow){

    printf("[%d %lld %lld %lld", (*toShow).x, toShow, (*toShow).left, (*toShow).right);

}

