#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "phonebook-sll.h"

void infoAdder(PBOOK* node);

void appendPrcs (PBOOK** start, int* size){

    char confirm;
    PBOOK* addNode = calloc(1, sizeof(PBOOK));
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
        PBOOK* lastNode = (*start);

        for(int i = 0; i < (*size) - 1; i++){
            lastNode = lastNode->next;
        }

        lastNode->next = addNode;
    }

    (*size)++;

    //saveToFile(all, size, maxSize);
    //saveToFile(all, size);
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

void infoAdder(PBOOK* node){
    strcpy(node->fname, appendMenu("Input First Name: "));
    strcpy(node->mname, appendMenu("Input Middle Name: "));
    strcpy(node->lname, appendMenu("Input Last Name: "));
    strcpy(node->num, appendMenu("Input Mobile Number: "));
    strcpy(node->email, appendMenu("Input Email: "));
}
