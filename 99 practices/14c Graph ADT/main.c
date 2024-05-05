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

            printf("Outbound: %c, Inbound: %c, Weight: %d\n", outBound, inBound, weight);

        // addition of vertex-edge pair
            // search of outbound in vertex list
                GRAPH** currentOutbound = &graph;
                while (*currentOutbound){
                    if ((*currentOutbound)->vertexName == outBound) break;
                    currentOutbound = &(*currentOutbound)->nextVertex;
                }

            // if not found, create new vertex
                if (!*currentOutbound){
                    GRAPH* newVertex = calloc(1, sizeof(GRAPH));
                    newVertex->vertexName = outBound;
                    *currentOutbound = newVertex;
                    vertexCount++;
                }

            // add to edge list
                GRAPH** currentEdge = &(*currentOutbound)->nextEdge;
                while (*currentEdge){
                    currentEdge = &(*currentEdge)->nextEdge;
                }

                GRAPH* newEdge = calloc(1, sizeof(GRAPH));
                newEdge->vertexName = inBound;
                newEdge->edgeWeight = weight;
                *currentEdge = newEdge;

            // addition of inbound to vertex list
                GRAPH** currentInbound = &graph;
                while (*currentInbound){
                    if ((*currentInbound)->vertexName == inBound) break;
                    currentInbound = &(*currentInbound)->nextVertex;
                }

                if (!*currentInbound){
                    GRAPH* newVertex = calloc(1, sizeof(GRAPH));
                    newVertex->vertexName = inBound;
                    *currentInbound = newVertex;
                    vertexCount++;
                }

    } while (!strchr(numeric, '!'));

    printf("Vertex count: %d\n\n", vertexCount);

    // create vertex list (for column labels)
    char* vertexList = calloc(vertexCount + 1, sizeof(char));
    {
        GRAPH* currentVertex = graph;
        for (int i = 0; i < vertexCount; i++){
            vertexList[i] = currentVertex->vertexName;
            currentVertex = currentVertex->nextVertex;
        }
    }

    printf("Adjacency matrix:\n"); // printing in adjacency matrix format
    {
        // print column labels
            printf("  ");
            for (int i = 0; i < vertexCount; i++){
                printf("%3c ", vertexList[i]);
            }
            printf("\n");

        // print row labels and data
            GRAPH* currentVertex = graph;
            for (int i = 0; i < vertexCount; i++){
                printf("%c ", vertexList[i]);
                for (int j = 0; j < vertexCount; j++){
                    GRAPH* currentEdge = currentVertex->nextEdge;
                    while (currentEdge){
                        if (currentEdge->vertexName == vertexList[j]){
                            printf("%3d ", currentEdge->edgeWeight);
                            break;
                        }
                        currentEdge = currentEdge->nextEdge;
                    }
                    if (!currentEdge) printf("    ");
                }
                printf("\n");
                
            
            }


    }




    printf("\nSUCCESS!\n");
    return 0;
}