// Topological Sort using Kahn's Algorithm (BFS-based)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    indegree[v]++;
}

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front > rear;
}

void topologicalSort(int vertices) {
    // Enqueue vertices with indegree 0
    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Sort: ");
    int count = 0;
    while (!isQueueEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        count++;

        for (int i = 0; i < vertices; i++) {
            if (adj[v][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    if (count != vertices)
        printf("\nCycle detected! Topological sort not possible.\n");
    else
        printf("\n");
}

int main() {
    int vertices = 6;
    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    topologicalSort(vertices);
    return 0;
}
