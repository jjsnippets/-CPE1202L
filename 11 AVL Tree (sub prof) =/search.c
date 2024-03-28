#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "search.h"
#include "display.h"
#include "formatting.h"

#include "zdebug.h"

void searchMenu(NODE* root){

    char* input = calloc(25, sizeof(char));
    int searchFor;
    NODE* match = root;

    COLOR_BLUE;
    printf("=== SEARCH A NODE ===\n");
    TEXT_RESET;
    printf("[S] Smallest node\n");
    printf("[L] Largest node\n");
    printf("Or enter a specific number\n");
    scanf(" %25[^\n]s", input);
    printf("\n");

    if (isdigit(*input)) {
        searchFor = atoi(input);

        match = searchNode(root, searchFor);

        if (!match)
            printf("Value %d is not found in tree!\n", searchFor);
        else
            printf("Value %d is in tree!\n", searchFor);

    } else {
        char userChoice = tolower(*input);

        if (userChoice == 's') while((match->left)) match = match->left;
        else while((match->right)) match = match->right;

        searchFor = match->data;

        printf("%s value is %d\n", (userChoice == 's') ? "Smallest" : "Largest", searchFor);
    }

    printf("Value in tree:");
    treeDisplay(root, searchFor);
    printf("\n");

    printf("Press any key to continue\n");
    getche();
}

NODE* searchNode(NODE* root, int x){
    NODE* result;

    if (!root)
        result = NULL;
    else if (root->data == x)
        result = root;
    else
        result = searchNode((root->data > x) ? root->left : root->right, x);
    
    return result;

}