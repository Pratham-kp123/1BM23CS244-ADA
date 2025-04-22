    #include <stdio.h>
    int n, a[10][10], res[10], s[10], top = 0;
    void dfs(int, int, int[][10]);
    void dfs_top(int, int[][10]);
    int main()
    {
    printf("Enter the no. of nodes");
    scanf("%d", &n);
    int i, j;
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
    scanf("%d", &a[i][j]);
    }
    }
    dfs_top(n, a);
    printf("Solution: ");
    for (int i = n - 1; i >= 0; i--) {
    printf("%d ", res[i]);
    }
    return 0;
    }
    void dfs_top(int n, int a[][10]) {
    int i;
    for (int i = 0; i < n; i++) {
    s[i] = 0;
    }
    for (int i = 0; i < n; i++) {
    if (s[i] == 0) {
    dfs(i, n, a);
    }
    }
    }
    void dfs(int j, int n, int a[][10]) {
    s[j] = 1;

    int i;
    for (int i = 0; i < n; i++) {
    if (a[j][i] == 1 && s[i] == 0) {
    dfs(i, n, a);
    }
    }
    res[top++] = j;
    }

/* Output: 
Enter the no. of nodes6
0 00 0 0 0 0 
0 0 0 0 0 0 
0 0 0 1 0 0 
0 1 0 0 0 0 
1 1 0 0 0 0 
1 0 1 0 0 0
Solution: 5 4 2 3 1 0

  */
