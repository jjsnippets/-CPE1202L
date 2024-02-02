// gcc -o phonebook-sll.exe -g phonebook-sll.c append-sll.c browse-sll.c change-sll.c delete-sll.c filehandling-sll.c

#ifndef PHONEBOOK_SLL_H
    #define PHONEBOOK_SLL_H

    typedef struct node{
        char fname[100];
        char mname[100];
        char lname[100];
        char num[100];
        char email[100];
        struct node* next;
    } NODE;

    // in phonebook-sll.c
    void mainMenuDisp();

    // in append-sll.c
    void appendPrcs (NODE** start, int* size);
    char* appendMenu(char* menu);
    void infoAdder(NODE* singleNode);

    // in browse-sll.c
    void displayChoiceMenu ();
    void browsePrcs (NODE** start, int* size);

    // in change-sll.c
    void changeChoiceMenu ();
    void changePrcs (NODE** start, int* size);

    // in delete-sll.c
    void deletePrcs (NODE** start, int* size);

    // in filehandling-sll.c
    void loadFromFile (NODE** start, int* size);
    void saveToFile (NODE** start, int* size);

#endif
