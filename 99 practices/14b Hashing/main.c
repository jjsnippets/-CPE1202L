#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "functions.h"

#define TEXT_RESET printf("\e[m")
#define BOLD_TEXT printf("\e[1m")
#define COLOR_RED printf("\e[91m")
#define COLOR_GREEN printf("\e[92m")
#define COLOR_BLUE printf("\e[94m")
#define COLOR_PINK printf("\e[95m")

void codeUpdate();

typedef struct list{
    int data;
    struct list* next;
} LIST;

// very innefficient, but easy to understand
int nextPrime(int num){

    while (num++){
        int isPrime = 1;

        for (int i = 2; i <= (int)sqrt(num); i++){
            if (num % i == 0){
                isPrime = 0;
                break;
            }
        }

        if (isPrime) return num;
    }
}

void openInsert(LIST* origList, int newValue){
    LIST* lastNode = origList;
    LIST* newNode = calloc(1, sizeof(LIST));
    newNode->data = newValue;

    while(lastNode->next) lastNode = lastNode->next;
    lastNode->next = newNode;
}

int main() {

    char* numbers = calloc(250, sizeof(char));
    char* current = calloc(25, sizeof(char));
    int size = 0;

    system("cls");
    codeUpdate();

    printf("Enter sequence of numbers\n");
    printf("Separated by spaces, ! as the terminator\n");
    scanf("%[^\n]249s", numbers);

    int* temp = calloc(strlen(numbers) / 2, sizeof(int));
    numbers[strlen(numbers)] = ' ';
    numbers[strlen(numbers)] = '!';

    printf("Generated list: {");

    for(current = strtok(numbers, " "); strcmp(current, "!"); current = strtok(NULL, " ")){
        temp[size++] = atoi(current);
        printf("%d, ", temp[size - 1]);
    }

    printf("\d\d}\n");
    printf("Size of list: %d\n\n", size);

    int* keys = calloc(size, sizeof(int));
    for(int i = 0; i < size; i++) keys[i] = temp[i];

    int prime1 = nextPrime(size);
    int prime2 = nextPrime(prime1);


    // open hashing
    {
        LIST* openHash = calloc(prime1, sizeof(LIST));
        for (int i = 0; i < prime1; i++){
            openHash[i].data = i;
            openHash[i].next = NULL;
        }

        COLOR_BLUE;
        printf("== Open hasing ===\n");
        TEXT_RESET;
        printf("Current hash function:\n");
        printf("H(k) = k mod %d\n", prime1);
        printf("\n");

        for (int i = 0; i < size; i++){
            int h = keys[i] % prime1;
            printf("H(%d) = %d mod %d = %d\n", keys[i], keys[i], prime1, h);

            openInsert(&openHash[h], keys[i]);
        }

        printf("\nFormed Hash Table:\n");
        for (int i = 0; i < prime1; i++){
            printf("%d: ", i);

            LIST* currentNode = openHash[i].next;
            if(currentNode){
                while(currentNode){
                    printf("%d -> ", currentNode->data);
                    currentNode = currentNode->next;
                }
                printf("\d\d\d\d\n");
            } else
                printf("\n");

        }

        printf("Complete!\n\n");

    }

    // linear hashing
    {
        int* linHash = calloc(prime1, sizeof(int));

        COLOR_BLUE;
        printf("== Linear hashing ===\n");
        TEXT_RESET;
        printf("Current hash function:\n");
        printf("H(k) = (i + k) mod %d\n", prime1);
        printf("\n");

        for (int h = 0; h < size; h++){
            for (int i = 0;; i++){
                int index = (i + keys[h]) % prime1;
                printf("H(%d) = (%d + %d) mod %d = %d", keys[h], i, keys[h], prime1, index);

                if(linHash[index]){
                    COLOR_RED;
                    printf("\tCollision!\n");
                    TEXT_RESET;
                    continue;
                } else {
                    printf("\n");
                    linHash[index] = keys[h];
                    break;
                }
            }
        }

        printf("\nFormed Hash Table:\n");
        for(int i = 0; i < prime1; i++){
            printf("%d: ", i);
            if(linHash[i]) printf("%d", linHash[i]);
            printf("\n");
        }

        printf("Complete!\n\n");
    }

    // quadratic hashing
    {
        int* quadHash = calloc(prime1, sizeof(int));

        COLOR_BLUE;
        printf("== Quadratic hashing ===\n");
        TEXT_RESET;
        printf("Current hash function:\n");
        printf("H(k) = (i^2 + k) mod %d\n", prime1);
        printf("\n");

        for (int h = 0; h < size; h++){
            for (int i = 0;; i++){
                int index = (i * i + keys[h]) % prime1;
                printf("H(%d) = (%d^2 + %d) mod %d = %d", keys[h], i, keys[h], prime1, index);

                if(quadHash[index]){
                    COLOR_RED;
                    printf("\tCollision!\n");
                    TEXT_RESET;
                    continue;
                } else {
                    printf("\n");
                    quadHash[index] = keys[h];
                    break;
                }
            }
        }

        printf("\nFormed Hash Table:\n");
        for(int i = 0; i < prime1; i++){
            printf("%d: ", i);
            if(quadHash[i]) printf("%d", quadHash[i]);
            printf("\n");
        }

        printf("Complete!\n\n");
    }


}

void codeUpdate(){
    printf("%d\n", __LINE__);
}
