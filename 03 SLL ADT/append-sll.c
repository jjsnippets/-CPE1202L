#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebook-sll.h"

void appendPrcs (NODE** start, int* size){

    char confirm;
    NODE* addNode = calloc(1, sizeof(NODE));
    addNode->next = NULL;

    infoAdder(addNode);

    printf("\nSave record [Y/N]?\n");
    confirm = tolower(getche());

    if (confirm == 'n'){
        free(addNode);
        return;
    }

    if(*size == 0){
        *start = addNode;
    } else {
        NODE* lastNode = (*start);

        for(int i = 0; i < (*size) - 1; i++){
            lastNode = lastNode->next;
        }

        lastNode->next = addNode;
    }

    (*size)++;

    saveToFile(start, size);
    printf("\n\nSaved successfully\n");
    fflush(stdin);
    getche();

    return;
}

char* appendMenu(char* menu){
    fflush(stdin);
    char* text = calloc(100, sizeof(char));
    printf("%s", menu);
    scanf("%[^\n,]s", text);
    return text;
}

void infoAdder(NODE* singleNode){
    strcpy(singleNode->fname, appendMenu("Input First Name: "));
    strcpy(singleNode->mname, appendMenu("Input Middle Name: "));
    strcpy(singleNode->lname, appendMenu("Input Last Name: "));
    strcpy(singleNode->num, appendMenu("Input Mobile Number: "));
    strcpy(singleNode->email, appendMenu("Input Email: "));
}
