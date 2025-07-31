// This assumes the graph is DAG (Directed Acyclic Graph)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Graph structure
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

void dfs(int v) {
    visited[v] = 1;
    Node* temp = adj[v];

    while (temp) {
        if (!visited[temp->vertex])
            dfs(temp->vertex);
        temp = temp->next;
    }
    stack[++top] = v;
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    printf("Topological Sort: ");
    while (top != -1)
        printf("%d ", stack[top--]);
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
