// in this file, I put some function about BFS.

#include"labyrinth.h"

list* createList() {
    list* head = (list*)malloc(sizeof(list));
    head->vex = NULL;
    head->next = NULL;
    return head;
} // checked

// judge that if the list is empty
int isEmpty(list* list) {
    if (list->next == NULL) return 0;
    else return 1;
} // checked

// put the element at the end of the list
void push(list* one, node* node) {
    list* onexit = (list*)malloc(sizeof(list));
    onexit->vex = node;
    onexit->next = NULL;
    list* prev = one;
    while (prev->next != NULL) {
        prev = prev->next;
    }
    prev->next = onexit;
} // checked

// pop the first element of the list
node* pop(list *li) {
    if(!isEmpty(li)) {
        printf("from function pop: empty list\n");
        return NULL;
    }
    list* one = li->next;
    li->next = one->next;
    node* ret = one->vex;
    free(one);
    return ret;
} // checked

// judge that if the node is already in CLOSED
// if so, return 1, or return 0
int init(node *nod, list*CLOSED) {
    list *lis = CLOSED->next;
    while (lis != NULL)
    {
        if (nod->id == lis->vex->id)
        {
            return 1;
        }
        lis = lis->next;
    }
    return 0;
}

// judge that if the node has children that are not in CLOSED and return them
// at the same time, when return children, mark them so that we can find the father node
// node** hasNext(node* node, Graph* g) {
//     int number = node->id;
//     int sum = 0;
//     node* r[max];
//     for (int i = 0; i < g->length; i++)
//     {
        
//     }
    
// }
// 不知道为什么node*r [max]会出问题

// judge that if the node has children that are not in CLOSED and return them
// at the same time, when return children, mark them so that we can find the father node
list* hasNext(node* node, Graph* g, list* CLOSED) {
    // printf("\n--------\nfrom hasNext\n");
    // printf("Current node: %d\n", node->id+1);
    int number = node->id;
    list* ret = createList();
    // get the node from g's matrix
    for(int i = 0; i < g->length; i++) {
        if (g->adjtype[number][i] != 1)
        {
            continue;
        }
        if (!init(&g->vexs[i], CLOSED)) {
            push(ret, &g->vexs[i]);
            g->vexs[i].father = node;
        }
    }

    // if not, print ret's node
    if(isEmpty(ret)) {
        // printf("this node's children: ");
        list* a = ret;
        while (a->next)
        {
            a = a->next;
            // printf("num%d ", a->vex->id+1);
        }
        // printf("\n--------\n\n");
    } 
    // else printf("no children\n--------\n\n");
    return ret;
}

int isTarget(node*Node, int target) {
    if(target-1 == Node->id) return 1;
    else return 0;
} // checked