#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "add.h"
#include "search.h"
#include "formatting.h"

#include "zdebug.h"

void searchMenu(NODE* root){

    char* input = calloc(25, sizeof(char));
    int searchFor;

    COLOR_BLUE;
    printf("=== SEARCH A NODE ===\n");
    TEXT_RESET;
    printf("[s] Smallest node\n");
    printf("[l] Largest node\n");
    printf("Or enter a specific number\n");
    scanf(" %25[^\n]s", input);

    if(isdigit(*input)){
        searchFor = atoi(input);
        



    }



    printf("Press any key to continue\n");
    getche();
}