#ifndef PHONEBOOK_SLL_H
    #define PHONEBOOK_SLL_H

    typedef struct pbook{
        char fname[100];
        char mname[100];
        char lname[100];
        char num[100];
        char email[100];
        struct pbook* next;
    } PBOOK;

    // in phonebook.c
    void mainMenuDisp();
    void saveToFile (PBOOK* node, int* size);

    // in append.c
    void appendPrcs (PBOOK** node, int* size);
    char* appendMenu(char* menu);

    // in browse.c
    void displayChoiceMenu ();
    void browsePrcs (PBOOK** node, int* size);

    // in change.c
    void changeChoiceMenu ();
    void changePrcs (PBOOK* node, int* size);

    // in delete.c
    void deletePrcs (PBOOK* node, int* size);

#endif
