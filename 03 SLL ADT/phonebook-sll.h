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

    // in phonebook.c
    void mainMenuDisp();
    void saveToFile (NODE* start, int* size);

    // in append.c
    void appendPrcs (NODE** start, int* size);
    char* appendMenu(char* menu);

    // in browse.c
    void displayChoiceMenu ();
    void browsePrcs (NODE** start, int* size);

    // in change.c
    void changeChoiceMenu ();
    void changePrcs (NODE* start, int* size);

    // in delete.c
    void deletePrcs (NODE* start, int* size);

#endif
