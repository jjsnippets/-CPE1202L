#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebook-sll.h"

void deletePrcs (NODE** start, int* size){

    char userInput;
    char* compare = calloc(100, sizeof(char));
    int inList = 0, indexList;

    printf("\n[L] Search by Last Name\n[N] Search by Mobile Number\n");
    fflush(stdin);
    userInput = tolower(getche());
    printf("\n\n");

    NODE* previousNode, * removeNode;
    // removeNode also acts as the currentNode

    switch (userInput) {
        case 'l':
        case 'n':

            printf("Input %s: ", (userInput == 'l' ? "Last Name" : "Mobile Number"));
            fflush(stdin);
            scanf("%[^\n,]s", compare);
            printf("\n");

            removeNode = *start;
            if (strcmp(compare, (userInput == 'l' ? removeNode->lname : removeNode->num) ) == 0)
                inList = 1;

            for(int i = 0; i < (*size - 1); i++){
                previousNode = (i == 0 ? *start : previousNode->next);
                removeNode = previousNode->next;
                if (strcmp(compare, (userInput == 'l' ? removeNode->lname : removeNode->num) ) == 0){
                    inList = 1;
                    break;
                }
            }

            if (!inList){
                printf("%s not found!\n", (userInput == 'l' ? "Last Name" : "Mobile Number"));
                fflush(stdin);
                getche();
                free(compare);
                return;
            }

            if (*size == 1){
                free(*start);
                *start = NULL;
            } else {
                previousNode->next = removeNode->next;
                free(removeNode);
            }

        break;

        default:
            free(compare);
            return;
    }

    (*size)--;

    saveToFile(start, size);
    printf("Entry Successfully deleted!\n");
    fflush(stdin);
    getche();

    free(compare);
    return;
}
