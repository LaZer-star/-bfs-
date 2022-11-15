// In this file, I put some function about initialize graphs.

#include "labyrinth.h"

Graph *CreateLabyrinth() {
    printf("start to create your labyrinth.\n");
    printf("input your size of the labyrinth' side: ");
    int size;
    scanf("%d", &size);

    Graph *graph = (Graph *)malloc(sizeof (Graph));
//    initialize the graph
    graph->length = size * size;
//    first initialize the vexs of the graph
    for (int i = 0; i < size * size; i++) {
        graph->vexs[i].id = i;
        graph->vexs[i].father = NULL;
    }

//    then initialize the matrix of the graph
    for (int i = 0; i < graph->length; i++) {
        for (int j = 0; j < graph->length; j++) {
            if (i > j) {
                graph->adjtype[i][j] = graph->adjtype[j][i];
                continue;
            }
            else if(i == j) {
                graph->adjtype[i][j] = 0;
                continue;
            }
            if(!isNearby(graph, &graph->vexs[j], &graph->vexs[i])) {
                graph->adjtype[i][j] = 1024;
                continue;
            }
            printf("is number%d vex and number%d vex connected?\nif so, press 1. if not, press 0: ", i+1, j+1);
            int road;
            scanf("%d", &road);
            if (road == 1) graph->adjtype[i][j] = road;
            else graph->adjtype[i][j] = max;
        }
    }
    return graph;
}


// if two vex is nearby, return 1 or 0
// whatever, a->id is larger than b->id
int isNearby(Graph *g, node* a, node* b) {
    if(abs(a->id - b->id) > sqrt(g->length)) return 0;
    else {
        if(abs(a->id - b->id) == sqrt(g->length)) return 1;
        if(abs(a->id - b->id) != 1) return 0;
        if(a->id % (int)sqrt(g->length) == 0) return 0;
    }
    return 1;
}