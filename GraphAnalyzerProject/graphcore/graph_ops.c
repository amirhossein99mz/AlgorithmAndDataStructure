#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
    int dest;
    int weight;
    struct Edge *next;
}Edge;

Edge *createEdge(int dest, int weight) {
    Edge *edge = malloc(sizeof(Edge));
    if (!edge) return NULL;
    edge->dest = dest;
    edge->weight = weight;
    edge->next = NULL;
    return edge;
}

void freeEdge(Edge *edge) {
    free(edge);
}

typedef struct {
    int size;
    Edge **adjList;
}Graph;

Graph *createGraph(int size) {
    Graph *graph = malloc(sizeof(Graph));
    if (!graph) return NULL;
    graph->size = size;
    graph->adjList = malloc(size*sizeof(Edge*));
    for (int i = 0; i < size; i++) graph->adjList[i] = NULL;
    return graph;
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->size; i++) free(graph->adjList[i]);
    free(graph);
}

void addEdge(Graph *graph, int dest, int weight, int src) {
    Edge *edge = createEdge(dest,weight);
    if (!edge) return;
    edge->next = graph->adjList[src];
    graph->adjList[src] = edge;
}

int isRegular(Graph *graph) {

    int *in = calloc(graph->size, sizeof(int));
    int *out = calloc(graph->size, sizeof(int));

    for (int u=0; u<graph->size; u++) {
        for (Edge* e = graph->adjList[u]; e; e = e->next) {
            out[u]++;
            int v = e->dest;
            in[v]++;
        }
    }

    int in1=in[0];
    int out1=out[0];
    for (int i=1; i<graph->size; i++) {
        if (in1!=in[0] || out1!=out[0]) return 0;
    }

    return 1;
}

void findSimplePath(Graph *graph,int u,int *visited,int *max,int sum) {
    visited[u] = 1;
    if (sum>*max) *max = sum;

    for (Edge* e = graph->adjList[u]; e; e = e->next) {
        int v = e->dest;
        if (!visited[v]) {
            findSimplePath(graph, v, visited, max, sum+e->dest);
        }
    }

    visited[u] = 0;
}
