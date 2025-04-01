#include <stdio.h>

int cost[10][10], n, t[10][2], sum;

void kruskal(int cost[10][10], int n);
int find(int parent[10], int i);

int main() {
  int i, j;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the cost adjacency matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);
    }
  }

  kruskal(cost, n);

  printf("Edges of the minimal spanning tree:\n");
  for (i = 0; i < n - 1; i++) {
    printf("(%d, %d) ", t[i][0], t[i][1]);
  }
  printf("\nSum of minimal spanning tree: %d\n", sum);
  return 0;
}

void kruskal(int cost[10][10], int n) {
  int min, u, v, count, k, parent[10];
  k = sum = 0;
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  count = 0;
  while (count < n - 1) {
    min = 999;
    u = v = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (find(parent, i) != find(parent, j) && cost[i][j] < min && cost[i][j] != 0) {
          min = cost[i][j];
          u = i;
          v = j;
        }
      }
    }
    if (u != -1) {
      parent[find(parent, u)] = find(parent, v);
      t[k][0] = u;
      t[k][1] = v;
      sum += min;
      k++;
      count++;
    } else {
        break;
    }
  }
}

int find(int parent[10], int i) {
  while (parent[i] != i) {
    i = parent[i];
  }
  return i;
}


/* Output: 
Enter the number of vertices: 5
Enter the cost adjacency matrix:
cost adjacency matrix:

0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
Edges of the minimal spanning tree:
(0, 1) (1, 2) (1, 4) (0, 3)
Sum of minimal spanning tree: 16
