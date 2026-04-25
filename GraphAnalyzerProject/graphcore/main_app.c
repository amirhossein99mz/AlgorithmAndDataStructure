#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int dest;
    int weight;
    struct Edge *next;
}Edge;

typedef struct {
    int size;
    Edge **adjList;
}Graph;

Graph *createGraph(int size);
void addEdge(Graph *graph, int dest, int weight, int src);
int isRegular(Graph *graph);
void findSimplePath(Graph *graph,int u,int *visited,int *max,int sum);

int main() {

    Graph *g = createGraph(4);

    addEdge(g,1,3,0);
    addEdge(g,2,2,1);
    addEdge(g,3,1,2);
    addEdge(g,0,4,3);

    printf("Regular: %d\n", isRegular(g));

    int visited[4] = {0};
    int max = 0;

    findSimplePath(g,0,visited,&max,0);
    printf("Max path weight: %d\n", max);

    return 0;
}
