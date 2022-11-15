//
// Created by lenovo on 2022/10/31.
//

#ifndef BFS_LABYRINTH_H
#define BFS_LABYRINTH_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max 1024

// initialize the node of labyrinth
typedef struct node
{
//    the number of the node
    int id;
//    the node before searching this node
    struct node* father;
}node;


// regard labyrinth as a graph
typedef struct Graph
{
//    total number of nodes in the graph
    int length;
//    put the vex of labyrinth
    node vexs[max];
//    initialize the nearby matrix
    int adjtype[max][max];
}Graph;


// create lists of OPEN, CLOSED in BFS
typedef struct List {
    node* vex;
    struct List* next;
}list;

list* createList();
int init(node *node, list*CLOSED);
list* hasNext(node* node, Graph* g, list* CLOSED);
Graph *CreateLabyrinth();
int isNearby(Graph *g, node*a, node*b);
node* pop(list *li);
int isEmpty(list* list);
void push(list* list, node* node);
int isTarget(node*Node, int target);


#endif //BFS_LABYRINTH_H
