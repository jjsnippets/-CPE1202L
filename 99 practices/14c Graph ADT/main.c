#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "graphs.h"

int main(){

    char* data = calloc(250, sizeof(char));
    char* numeric = calloc(25, sizeof(char));
    int graphSize = 0;

    system("cls");

    printf("Enter series of vertices and weights\n");
    printf("Outbound_1, Inbound_1, Weight_1, [...] ! as the terminator\n");
    printf("Example: A, B, 5, B, C, 7, C, A, 3 !\n");
    
    scanf("%[^\n]249s", data);
    printf("\n");

    do{
        char outBound = strtok(graphSize ? NULL : data, ", ")[0];
        char inBound = strtok(NULL, ", ")[0];
        memset(numeric, 0, 25);
        strcpy(numeric, strtok(NULL, ", "));
        int weight = atoi(numeric);

        graphSize++;
        printf("Outbound: %c, Inbound: %c, Weight: %d\n", outBound, inBound, weight);

    } while (!strchr(numeric, '!'));
}