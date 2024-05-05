#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIRECTED 0

#define TEXT_RESET printf("\e[m")
#define COLOR_GRAY printf("\e[90m")
#define ROW_COLOR printf("\e[46m")
#define COL_COLOR printf("\e[44m")

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

    GRAPH* toVertex = *graph;
    while (toVertex){
        if (toVertex->vertexName == inBound) break;
        toVertex = toVertex->nextVertex;
    }

    GRAPH** currentEdge = &(*currentOutbound)->nextEdge;
    // if empty, create new edge
    if(!*currentEdge){
        *currentEdge = calloc(1, sizeof(GRAPH));
        (*currentEdge)->vertexName = inBound;
        (*currentEdge)->edgeWeight = weight;
        (*currentEdge)->nextVertex = toVertex;
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
    newEdge->nextVertex = toVertex;

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
            ROW_COLOR;
            printf("%3c ", currentVertex->vertexName);
            TEXT_RESET;
            vertexList[i] = currentVertex->vertexName;
            currentVertex = currentVertex->nextVertex;
        }
        printf("\n");
    }

    // print row labels and data
    GRAPH* currentVertex = graph;

    for (int i = 0; i < vertexCount; i++){
        COL_COLOR;
        printf("%c ", vertexList[i]);
        TEXT_RESET;

        GRAPH* currentEdge = currentVertex->nextEdge;
        for (int j = 0, k = 0; j < vertexCount; j++){
            if (currentEdge && currentEdge->vertexName == vertexList[j]){
                printf("%3d ", currentEdge->edgeWeight);
                currentEdge = currentEdge->nextEdge;
                k++;
            } else {
                COLOR_GRAY;
                printf("  * ");
                TEXT_RESET;
            }
        }
        printf("\n");
        currentVertex = currentVertex->nextVertex;
    }
    printf("\n");

}

void printLists(GRAPH* graph, int vertexCount){
    printf("Adjacency List:\n");

    GRAPH* currentVertex = graph;
    while (currentVertex){
        // per vertex
        printf("{%c} -> ", currentVertex->vertexName);

        GRAPH* currentEdge = currentVertex->nextEdge;
        while (currentEdge){
            // per edge
            printf("[%c <%d>] -> ", currentEdge->vertexName, currentEdge->edgeWeight);
            currentEdge = currentEdge->nextEdge;
        }
        printf("\b\b\b\b    \n");
        currentVertex = currentVertex->nextVertex;
    }
    printf("\n");
}

void push(LIST** list, GRAPH* data){
    LIST* newNode = calloc(1, sizeof(LIST));
    newNode->data = data;
    newNode->next = *list;
    *list = newNode;
}

GRAPH* pop(LIST** list){
    if (!*list) return NULL;
    GRAPH* data = (*list)->data;
    *list = (*list)->next;
    return data;
}

void enqueue(LIST** list, GRAPH* data){
    LIST* newNode = calloc(1, sizeof(LIST));
    newNode->data = data;
    if (!*list){
        *list = newNode;
        return;
    }

    LIST* current = *list;
    while (current->next) current = current->next;
    current->next = newNode;
}

GRAPH* dequeue(LIST** list){
    if (!*list) return NULL;
    GRAPH* data = (*list)->data;
    *list = (*list)->next;
    return data;
}

int isInList(LIST* list, char data){
    while (list){
        if (list->data->vertexName == data) return 1;
        list = list->next;
    }
    return 0;
}

void zeroVisited(GRAPH* graph){
    GRAPH* currentVertex = graph;
    while (currentVertex){
        currentVertex->visited = 0;
        GRAPH* currentEdge = currentVertex->nextEdge;
        while (currentEdge){
            currentEdge->visited = 0;
            currentEdge = currentEdge->nextEdge;
        }
        currentVertex = currentVertex->nextVertex;
    }
}

void depthFirstTraversal(GRAPH* graph, int vertexCount){
    printf("Depth First Traversal: \n");

    zeroVisited(graph);
    LIST* stack = NULL;

    GRAPH* currentVertex = graph;
    push(&stack, currentVertex);

    while (stack){
        currentVertex = pop(&stack);
        if (!currentVertex->visited){
            printf("\n%c -> ", currentVertex->vertexName);
            currentVertex->visited = 1;
            
            GRAPH* currentEdge = currentVertex->nextEdge;
            while (currentEdge){
                if (!currentEdge->nextVertex->visited && !isInList(stack, currentEdge->vertexName)){
                    push(&stack, currentEdge->nextVertex);
                    printf("[%c] ", currentEdge->vertexName);
                }
                currentEdge = currentEdge->nextEdge;
            }
        }
    }

    printf("\b\b\b\b     \n");
    
}

int main(){

    char* data = calloc(250, sizeof(char));
    char* numeric = calloc(25, sizeof(char));
    int vertexCount = 0;

    GRAPH* graph = NULL;

    printf("Graph ADT\n\n");
    system("cls");

    printf("Graph ADT\n");
    printf("Enter series of vertices and weights\n");
    printf("Outbound_1, Inbound_1, Weight_1, [...]! as the terminator\n");
    printf("Example: A, B, 5, B, C, 7, C, A, 3!\n");
    printf("Test case: a, x, 1, x, h, 2, x, g, 3, g, h, 4, g, p, 5, h, p, 6, h, e, 7, e, y, 8, e, m, 9, y, m, 11, m, j, 11!\n");
    
    scanf("%[^\n]249s", data);
    printf("\n");

    do{
        // user input and parsing
            char outBound = toupper(strtok(vertexCount ? NULL : data, ", ")[0]);
            char inBound = toupper(strtok(NULL, ", ")[0]);
            memset(numeric, 0, 25);
            strcpy(numeric, strtok(NULL, ", "));
            int weight = atoi(numeric);

        // addition of vertex-edge pair
            addVertex(&graph, &vertexCount, outBound);
            addVertex(&graph, &vertexCount, inBound);
            addEdge(&graph, outBound, inBound, weight);
            if(!DIRECTED) addEdge(&graph, inBound, outBound, weight);

    } while (!strchr(numeric, '!'));

    printf("Vertex count: %d\n", vertexCount);
    printMatrix(graph, vertexCount);
    printLists(graph, vertexCount);

    depthFirstTraversal(graph, vertexCount);

    printf("\nSUCCESS!\n");
    return 0;
}