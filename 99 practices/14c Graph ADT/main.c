#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct graph{
    char vertexName;
    int edgeWeight;
    int visited;
    struct graph* nextVertex;
    struct graph* nextEdge;
} GRAPH;

typedef struct list{
    GRAPH* data;
    struct list* next;
} LIST;

void addVertex(GRAPH** graph, int* vertexCount, char name){
    // if empty, create new vertex
    if(!*graph){
        *graph = calloc(1, sizeof(GRAPH));
        (*graph)->vertexName = name;
        (*vertexCount)++;
        return;
    }

    // otherwise search in vertex list
    GRAPH** currentOutbound = graph;
    while (*currentOutbound && (*currentOutbound)->vertexName <= name){
        if ((*currentOutbound)->vertexName == name) return;
        currentOutbound = &((*currentOutbound)->nextVertex);
    }

    GRAPH* newVertex = calloc(1, sizeof(GRAPH));
    newVertex->vertexName = name;

    // if at the end of the list, then insert at end
    if (!*currentOutbound){
        *currentOutbound = newVertex;
    
    // else, displace the current vertex to next position
    } else {
        GRAPH* temp = (*currentOutbound);
        (*currentOutbound) = newVertex;
        newVertex->nextVertex = temp;
    }

    (*vertexCount)++;
}

void addEdge(GRAPH** graph, char outBound, char inBound, int weight){
    GRAPH** currentOutbound = graph;
    while (*currentOutbound){
        if ((*currentOutbound)->vertexName == outBound) break;
        currentOutbound = &(*currentOutbound)->nextVertex;
    }

    GRAPH** currentEdge = &(*currentOutbound)->nextEdge;
    // if empty, create new edge
    if(!*currentEdge){
        *currentEdge = calloc(1, sizeof(GRAPH));
        (*currentEdge)->vertexName = inBound;
        (*currentEdge)->edgeWeight = weight;
        return;
    }

    // otherwise search in edge list
    while (*currentEdge && (*currentEdge)->vertexName <= inBound){
        if ((*currentEdge)->vertexName == inBound) return;
        currentEdge = &((*currentEdge)->nextEdge);
    }

    GRAPH* newEdge = calloc(1, sizeof(GRAPH));
    newEdge->vertexName = inBound;
    newEdge->edgeWeight = weight;

    // if at the end of the list, then insert at end
    if (!*currentEdge){
        *currentEdge = newEdge;
    
    // else, displace the current vertex to next position
    } else {
        GRAPH* temp = (*currentEdge);
        (*currentEdge) = newEdge;
        newEdge->nextEdge = temp;
    }
}

void printMatrix(GRAPH* graph, int vertexCount){

    printf("\nAdjacency matrix:\n");
    
    char* vertexList = calloc(vertexCount + 1, sizeof(char));
    // print column labels
    {
        printf("  ");
        GRAPH* currentVertex = graph;
        for (int i = 0; i < vertexCount; i++){
            printf("%3c ", currentVertex->vertexName);
            vertexList[i] = currentVertex->vertexName;
            currentVertex = currentVertex->nextVertex;
        }
        printf("\n");
    }

    // print row labels and data
    {     
        GRAPH* currentVertex = graph;
        for (int i = 0; i < vertexCount; i++){
            printf("%c ", vertexList[i]);
            for (int j = 0; j < vertexCount; j++){
                GRAPH* currentEdge = currentVertex->nextEdge;
                
                while (currentEdge){
                    if (currentEdge->vertexName == vertexList[j])
                        printf("%3d ", currentEdge->edgeWeight);
                    else 
                        if (!currentEdge) printf("  * ");
                    currentEdge = currentEdge->nextEdge;
                }
            }
            printf("\n");
        }
    }
}

int main(){

    char* data = calloc(250, sizeof(char));
    char* numeric = calloc(25, sizeof(char));
    int vertexCount = 0;

    GRAPH* graph = NULL;

    system("cls");

    printf("Enter series of vertices and weights\n");
    printf("Outbound_1, Inbound_1, Weight_1, [...]! as the terminator\n");
    printf("Example: A, B, 5, B, C, 7, C, A, 3!\n");
    
    scanf("%[^\n]249s", data);
    printf("\n");

    do{
        // user input and parsing
            char outBound = toupper(strtok(vertexCount ? NULL : data, ", ")[0]);
            char inBound = toupper(strtok(NULL, ", ")[0]);
            memset(numeric, 0, 25);
            strcpy(numeric, strtok(NULL, ", "));
            int weight = atoi(numeric);

            printf("\nOutbound: %c, Inbound: %c, Weight: %d\n", outBound, inBound, weight);

        // addition of vertex-edge pair
            addVertex(&graph, &vertexCount, outBound);
            printMatrix(graph, vertexCount);
            addEdge(&graph, outBound, inBound, weight);
            printMatrix(graph, vertexCount);
            addVertex(&graph, &vertexCount, inBound);
            printMatrix(graph, vertexCount);

    } while (!strchr(numeric, '!'));

    printf("Vertex count: %d\n\n", vertexCount);

    printMatrix(graph, vertexCount);

    printf("\nSUCCESS!\n");
    return 0;
}