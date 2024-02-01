#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebook-sll.h"

void changePrcs (NODE** start, int* size){

    char userInput;
    char* compare = calloc(100, sizeof(char));
    int inList = 0, indexNode;

    char* separator = calloc(80, sizeof(char));
    memset(separator, '=', 79);

    NODE* currentNode;

    do {
        inList = 0;
        memset(compare, '\0', 100);

        printf("\n[L] Search by Last Name\n[N] Search by Mobile Number\n");
        fflush(stdin);
        userInput = tolower(getche());
        printf("\n\n");

        switch (userInput) {
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
                    printf("%s not found!\n", (userInput == 'l' ? "Last Name" : "Mobile Number"));
                    fflush(stdin);
                    getche();
                    free(compare);
                    free(separator);
                    return;
                }

                break;

            default:
                free(compare);
                free(separator);
                return;
        }

        printf("\n");
        printf("%-15s %-15s %-15s %-15s %-15s\n", "Last Name", "First Name", "Middle Name", "Mobile No.", "Email Address");
        printf("%s\n", separator);
        printf("%-15s %-15s %-15s %-15s %-15s\n", currentNode->lname, currentNode->mname, currentNode->fname, currentNode->num, currentNode->email);
        printf("\n");

        changeChoiceMenu();
        fflush(stdin);
        userInput = tolower(getche());
        printf("\n\n");

        printf("Replace with: ");
        fflush(stdin);
        memset(compare, '\0', 100);
        scanf("%[^\n,]s", compare);
        printf("\n");

        switch (userInput) {
        case 'l':
            strcpy(currentNode->lname, compare);
            break;

        case 'm':
            strcpy(currentNode->mname, compare);
            break;

        case 'f':
            strcpy(currentNode->fname, compare);
            break;

        case 'n':
            strcpy(currentNode->num, compare);
            break;

        case 'e':
            strcpy(currentNode->email, compare);
            break;
        }

        printf("\n");
        printf("%-15s %-15s %-15s %-15s %-15s\n", "Last Name", "First Name", "Middle Name", "Mobile No.", "Email Address");
        printf("%s\n", separator);
        printf("%-15s %-15s %-15s %-15s %-15s\n", currentNode->lname, currentNode->fname, currentNode->mname, currentNode->num, currentNode->email);
        printf("\n\n");

        //saveToFile(all, size);
        printf("Again [Y/N]\n");
        fflush(stdin);
        userInput = tolower(getche());
        printf("\n\n");

    } while (userInput != 'n');

    free(compare);
    free(separator);

}

void changeChoiceMenu (){

    printf("Change What?\n");
    printf("[L] Last Name\n");
    printf("[M] Middle Name\n");
    printf("[F] First Name\n");
    printf("[N] Mobile Number\n");
    printf("[E] Email Address\n");

}
