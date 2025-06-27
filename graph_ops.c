#include <stdio.h>
#include <stdbool.h>
#include "graph_ops.h"

#define MAX 10

int graph[MAX][MAX];
bool visited[MAX];
int n;

void dfs(int v) {
    visited[v] = true;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

void reset_visited() {
    for (int i = 0; i < MAX; i++)
        visited[i] = false;
}

void graph_menu() {
    int choice, start;
    printf("Enter number of nodes (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    do {
        printf("\n--- Graph Operations ---\n");
        printf("1. BFS\n2. DFS\n0. Back to Main Menu\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting node: ");
                scanf("%d", &start);
                reset_visited();
                printf("BFS Traversal: ");
                bfs(start);
                printf("\n");
                break;

            case 2:
                printf("Enter starting node: ");
                scanf("%d", &start);
                reset_visited();
                printf("DFS Traversal: ");
                dfs(start);
                printf("\n");
                break;

            case 0:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);
}
