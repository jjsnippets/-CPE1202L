#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "phonebook-sll.h"

#define FILENAME "phonebook.txt"

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

void loadFromFile (NODE** start, int* size){

    FILE* fp = fopen(FILENAME, "r");
    char* row = calloc(1000, sizeof(char));

    if (fp == NULL){
       printf("A file named \"%s\" was not found. This will be automatically made after using this program.\n", FILENAME);
       getche();
       fclose(fp);
       return;
    }

    // minimal error correction: checks if header is correct
    fgets(row, 1000, fp);
    if (strcmp(row, ",lname,mname,fname,num,email\n") != 0){
        printf("File format of \"%s\" is wrong. No data will be loaded in.\n", FILENAME);
        getche();
        fclose(fp);
        return;
    }

    while (fgets(row, 1000, fp) != NULL)
    {
        NODE* addNode = calloc(1, sizeof(NODE));
        addNode->next = NULL;

        // grabs individual values from rows
        strtok(row, ","); // skips index
        strcpy(addNode->fname, strtok(NULL, ","));
        strcpy(addNode->mname, strtok(NULL, ","));
        strcpy(addNode->lname, strtok(NULL, ","));
        strcpy(addNode->num, strtok(NULL, ","));
        strcpy(addNode->email, strtok(NULL, "\n"));

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
    }

    printf("Data from \"%s\" successfully loaded!\n", FILENAME);
    getche();
    fclose(fp);

}