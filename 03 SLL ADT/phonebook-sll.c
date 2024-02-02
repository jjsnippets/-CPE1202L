#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebook-sll.h"

#define FILENAME "phonebook.txt"

void main(){

    NODE* startPBook;
    NODE* nodeDisplay;

    int currSizePBook = 0;
    char userInput;

    while (1){

        mainMenuDisp();
        printf("He\n");

        for(int i = 0; i < currSizePBook; i++){
            nodeDisplay = (i == 0 ? startPBook : nodeDisplay->next);
            printf("%s %s %s %s %s [%d]\n", nodeDisplay->lname, nodeDisplay->fname, nodeDisplay->mname,nodeDisplay->num, nodeDisplay->email, currSizePBook);
        }

        printf("Ho\n");

        fflush(stdin);
        userInput = tolower(getche());

        if (userInput == 'e')
            break;

        printf("\n\n");

        switch (userInput){

            case 'a':
                appendPrcs(&startPBook, &currSizePBook);
                break;

            case 'b':
                browsePrcs(&startPBook, &currSizePBook);
                break;

            case 'c':
                changePrcs(&startPBook, &currSizePBook);
                break;

            case 'd':
                deletePrcs(&startPBook, &currSizePBook);
                break;

        }

    }

    saveToFile(&startPBook, &currSizePBook);
    free(startPBook);

}


void mainMenuDisp() {
    system("cls");
    printf("[A]ppend\n");
    printf("[B]rowse\n");
    printf("[C]hange\n");
    printf("[D]elete\n");
    printf("[E]xit\n");
    printf("\n");
}

void saveToFile (NODE** start, int* size){
    NODE* currentNode;

    FILE* fp = fopen(FILENAME, "w");
    rewind(fp);

    fprintf(fp, ",lname,mname,fname,num,email\n");

    for(int i = 0; i < *size; i++){
        currentNode = (i == 0 ? *start : currentNode->next);
        fprintf(fp, "%d,%s,%s,%s,%s,%s\n", i, currentNode->lname, currentNode->fname, currentNode->mname,currentNode->num, currentNode->email);
    }

    fclose(fp);
}
