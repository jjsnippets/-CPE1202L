#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

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
    void displayAll(NODE* root);

    void addNode(NODE** root, int data);
    void deleteNode(NODE** root, int data, int* count);

    void addMenu(NODE** root);
    void deleteMenu(NODE** root, int* count);

    void traversalMenu(NODE** root);
    void breadthFirst(NODE** root);
    void inOrder(NODE* root, int depth);
    void preOrder(NODE* root, int depth);
    void postOrder(NODE* root, int depth);

    void treeDisplay(NODE* root, int depth);
    void treeMode(NODE* root);
    int treeDepth(NODE* root, int depth);

    void enqueue(QUEUE** head, NODE* toAdd);
    NODE* dequeue(QUEUE** head);

#endif // FUNCTIONS_H
