#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebook-sll.h"

void browsePrcs(NODE** start, int* size){

    char userInput = 'a';
    char* compare = calloc(100, sizeof(char));
    int inList;

    NODE* currentNode;

    do {
        inList = 0;
        memset(compare, '\0', 100);

        displayChoiceMenu();
        fflush(stdin);
        userInput = tolower(getche());
        printf("\n\n");


        switch (userInput) {
            case 'b':

                displayTable(*start, 1);
                break;

            case 'l':
            case 'n':
                printf("Input %s: ", (userInput == 'l' ? "Last Name" : "Mobile Number"));
                fflush(stdin);
                scanf("%[^\n,]s", compare);
                printf("\n");

                for(int i = 0; i < *size; i++){
                    currentNode = (i == 0 ? *start : currentNode->next);
                    if (strcmp(compare, (userInput == 'l' ? currentNode->lname : currentNode->num) ) == 0){
                        inList = 1;
                        break;
                    }

                }

                if (!inList){
                    printf("%s not found!\n\n", (userInput == 'l' ? "Last Name" : "Mobile Number"));
                    printf("Press any key to continue\n");
                    break;
                }

                displayTable(currentNode, 0);
                break;

        }

        printf("Again [Y/N]\n");
        fflush(stdin);
        userInput = tolower(getche());
        printf("\n\n");

    } while ( userInput != 'n');

    free(compare);
    return;

}

void displayChoiceMenu(){

    printf("[B]rowse All\n");
    printf("[L] Browse by Last Name\n");
    printf("[N] Browse by Mobile Number\n");

}

void displayTable(NODE* currentNode, int showAll){

    char* separator = calloc(80, sizeof(char));
    memset(separator, '=', 79);

    printf("%-15s %-15s %-15s %-15s %-15s\n", "Last Name", "First Name", "Middle Name", "Mobile No.", "Email Address");
    printf("%s\n", separator);

    for(int i = 0; currentNode != NULL; i++){
        printf("%-15s %-15s %-15s %-15s %-15s\n", currentNode->lname, currentNode->fname, currentNode->mname,currentNode->num, currentNode->email);
        currentNode = currentNode->next;
        if (!showAll) break;
    }

    printf("\n");

    free(separator);
    return;

}
