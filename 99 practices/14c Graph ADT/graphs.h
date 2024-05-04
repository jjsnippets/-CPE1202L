#ifndef GRAPHS_H
    #define GRAPHS_H

    typedef struct graph{
        char vertexName;
        int edgeWeight;
        int visited;
        struct graph* nextVertex;
        struct graph* nextEdge;
    } GRAPH;

    typedef struct list{
        graph* data;
        struct list* next;
    } LIST;


#endif