#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebook-sll.h"

void browsePrcs(PBOOK** start, int* size){

    char userInput = 'a';
    char* compare = calloc(100, sizeof(char));
    int inList;

    char* separator = calloc(80, sizeof(char));
    memset(separator, '=', 79);

    PBOOK* currentNode;

    do {
        inList = 0;
        memset(compare, '\0', 100);

        displayChoiceMenu();
        fflush(stdin);
        userInput = tolower(getche());

        printf("\n");

        switch (userInput) {
            case 'b':
                printf("%-15s %-15s %-15s %-15s %-15s\n", "Last Name", "First Name", "Middle Name", "Mobile No.", "Email Address");
                printf("%s\n", separator);

                for(int i = 0; i < *size; i++){
                    currentNode = (i == 0 ? *start : currentNode->next);
                    printf("%-15s %-15s %-15s %-15s %-15s\n", currentNode->lname, currentNode->fname, currentNode->mname,currentNode->num, currentNode->email);
                }

                printf("\n");

                break;

            case 'l':
                printf("Input Last Name: ");
                fflush(stdin);
                scanf("%[^\n,]s", compare);
                printf("\n");

                for(int i = 0; i < *size; i++){
                    currentNode = (i == 0 ? *start : currentNode->next);
                    if (strcmp(compare, currentNode->lname) == 0){
                        inList = 1;
                        break;
                    }

                }

                if (!inList){
                    printf("Last Name not found!\n");
                    break;
                }

                printf("%-15s %-15s %-15s %-15s %-15s\n", "Last Name", "First Name", "Middle Name", "Mobile No.", "Email Address");
                printf("%s\n", separator);
                printf("%-15s %-15s %-15s %-15s %-15s\n", currentNode->lname, currentNode->mname, currentNode->fname, currentNode->num, currentNode->email);
                printf("\n");

                break;

            case 'n':
                printf("Input Mobile Number: ");
                fflush(stdin);
                scanf("%[^\n,]s", compare);
                printf("\n");

                for(int i = 0; i < *size; i++){
                    currentNode = (i == 0 ? *start : currentNode->next);
                    if (strcmp(compare, currentNode->num) == 0){
                        inList = 1;
                        break;
                    }

                }

                if (!inList){
                    printf("Mobile Number not found!\n\n");
                    break;
                }

                printf("%-15s %-15s %-15s %-15s %-15s\n", "Last Name", "First Name", "Middle Name", "Mobile No.", "Email Address");
                printf("%s\n", separator);
                printf("%-15s %-15s %-15s %-15s %-15s\n", currentNode->lname, currentNode->fname, currentNode->mname, currentNode->num, currentNode->email);
                printf("\n");

                break;
        }

        printf("Again [Y/N]\n");
        fflush(stdin);
        userInput = tolower(getche());

    } while ( userInput != 'n');

    free(compare);
    free(separator);
    return;

}



void displayChoiceMenu(){

    printf("\n\n");
    printf("[B]rowse All\n");
    printf("[L] Browse by Last Name\n");
    printf("[N] Browse by Mobile Number\n");

}
