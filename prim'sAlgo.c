#include <stdio.h>

#define V 5
#define INT_MAX 9999999

int minval(int key[], int visited[]) {
  int mini = INT_MAX;
  int mini_index;

  for (int i = 0; i < V; i++) {
    if (visited[i] == 0 && key[i] < mini) {
      mini = key[i];
      mini_index = i;
    }
  }
  return mini_index;
}

void primsAlgorithm(int graph[V][V]) {
  int parent[V];
  parent[0] = -1;

  int key[V];
  int visited[V];
  for (int i = 0; i < V; i++) {
    key[i] = INT_MAX;
    visited[i] = 0;
  }
  key[0] = 0;

  int totalCost = 0;

  for (int i = 0; i < V; i++) {
    int u = minval(key, visited);
    visited[u] = 1;

    for (int j = 0; j < V; j++) {
      if (graph[u][j] && visited[j] == 0 && graph[u][j] < key[j]) {
        parent[j] = u;
        key[j] = graph[u][j];
      }
    }
  }

  printminispantree(parent, graph, &totalCost);

  printf("\nTotal cost of the MST: %d\n", totalCost);
}

void printminispantree(int parent[], int graph[V][V], int *totalCost) {
  printf("Edge   Weight\n");
  for (int i = 1; i < V; i++) {
    printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    *totalCost += graph[i][parent[i]];
  }
}

int main() {
  int graph[V][V];

  printf("Enter the adjacency matrix row-wise:\n");
  for (int i = 0; i < V; i++) {
    printf("Enter the adjacency vector for vertex %d: ", i);
    for (int j = 0; j < V; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  primsAlgorithm(graph);
  return 0;
}

/*Output: 
Enter the adjacency matrix row-wise:
Enter the adjacency vector for vertex 0: 0 2 0 6 0
Enter the adjacency vector for vertex 1: 2 0 3 8 5
Enter the adjacency vector for vertex 2: 0 3 0 0 7
Enter the adjacency vector for vertex 3: 6 8 0 0 9
Enter the adjacency vector for vertex 4: 0 5 7 9 0
Edge   Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5

Total cost of the MST: 16
  */
