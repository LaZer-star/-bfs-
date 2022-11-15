// in this project, you can solve the problem: labyrinth

#include "labyrinth.h" // this head file is in include

int main() {
    list* OPEN = createList();
    list* CLOSED = createList();
    Graph *g = CreateLabyrinth();
    
    int target;
    printf("input your target: ");
    scanf("%d", &target);

    // push(CLOSED, g->vexs[1]);

    // step1: put the first node in the graph to the OPEN
    push(OPEN, &g->vexs[0]);

    // step2: judge if OPEN is empty
    // if so, into the while loop
    while (isEmpty(OPEN))
    {
        // put a node(n) from OPEN to CLOSED
        node* n = pop(OPEN);
        push(CLOSED, n);
        list*children = hasNext(n, g, CLOSED);

        // find out the children of n and put them into OPEN, and make these children can find n
        while (isEmpty(children)) {
            node* Node = pop(children);
            push(OPEN, Node);

            if (isTarget(Node, target)) 
            {
                printf("\nsuccess!\nthe way is: %d", Node->id+1);
                while (Node->father)
                {
                    Node = Node->father;
                    printf("<-%d", Node->id+1);
                }
                return 0;
            }
        }
    }
    printf("no way!");
    return 0;
}
