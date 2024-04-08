#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    // reset text alterations
    #define TEXT_RESET printf("\e[m")

    // only one of the following text alterations can be applied at a time
        // applies bold to text
        #define BOLD_TEXT printf("\e[1m")
        
        // applies color to text
        #define COLOR_RED printf("\e[91m")
        #define COLOR_GREEN printf("\e[92m")
        #define COLOR_BLUE printf("\e[94m")
        #define COLOR_PINK printf("\e[95m") 

    // moves cursor by 'x' spaces
    #define MOVE_UP(x) printf("\e[%dA", x)
    #define MOVE_DOWN(x) printf("\e[%dB", x)
    #define MOVE_LEFT(x) printf("\e[%dD", x)

    // structure definitions
    typedef struct node {
        int x;
        struct node* left;
        struct node* right;
    } NODE;

    typedef struct queue {
        NODE* data;
        struct queue* next;
    } QUEUE;

    // in add.c
    void addMenu(NODE** root, int* count);
    void addNode(NODE** root, int data, int* size);

    // in delete.c
    void deleteMenu(NODE** root, int* count);
    int deleteNode(NODE** root, int data, int* size);
    NODE* searchNode(NODE* tree, int find);

    // in traverse.c
    void traversalMenu(NODE** root, int* count);
    void breadthFirst(NODE** root);
    void inOrder(NODE* root, int depth);
    void preOrder(NODE* root, int depth);
    void postOrder(NODE* root, int depth);

    void treeDisplay(NODE* root, int depth);
    void treeMode(NODE* root);
    int treeDepth(NODE* root, int depth);

    void enqueue(QUEUE** head, NODE* toAdd);
    NODE* dequeue(QUEUE** head);

#endif
