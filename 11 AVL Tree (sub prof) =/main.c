#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "add.h"
#include "delete.h"
#include "display.h"
#include "search.h"
#include "formatting.h"

#include "balance.h"

int main(){

    NODE* root = NULL;
    char userInput;

    // [10, 6, 2, 21, 17, 13, 9, 5, 1, 20, 16]
    // for (int i = 0; i < 11; i++) {
    //     LIST* check = addNode(&root, ((i+9)*295) % 23);
    //     balanceTree(&root, check);
    // }

    do{
        system("cls");
        BOLD_TEXT;
        printf("=== MAIN MENU ===\n");
        TEXT_RESET;
        printf("[1] Add new node\n");
        printf("[2] Delete a node\n");
        printf("[3] Search for a node\n");
        printf("[4] Traverse binary tree\n");
        printf("[5] Exit\n");

        userInput = getche();
        printf("\n\n");

        switch (userInput) {
            case '1':
                addMenu(&root);
                break;

            case '2':
                deleteMenu(&root);
                break;

            case '3':
                searchMenu(root);
                break;

            case '4':
                displayMenu(root);
                break;
        }
    } while (userInput != '5');


}