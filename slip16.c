SLIP 16


Q.1) Write a program to implement to find out solution for 0/1 knapsack problem using
dynamic programming.


#include <stdio.h>
#define MAX 100
 
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];
 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value = %d\n", dp[n][W]);

    return 0;
}



Q.2) Write a program to determine if a given graph is a Hamiltonian cycle or not.


#include <stdio.h>
#define MAX 100

int graph[MAX][MAX];
int path[MAX];
int V;
 
int isSafe(int v, int pos) {
    
    if (graph[path[pos - 1]][v] == 0)
        return 0;
 
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return 0;
    }

    return 1;
}
 
int hamCycleUtil(int pos) {
   
    if (pos == V) {
   
        return graph[path[pos - 1]][path[0]] == 1;
    }
 
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            if (hamCycleUtil(pos + 1))
                return 1;

            path[pos] = -1; 
        }
    }

    return 0;
}

void hamCycle() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;  

    if (!hamCycleUtil(1)) {
        printf("No Hamiltonian Cycle exists\n");
        return;
    }

    printf("Hamiltonian Cycle:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);

    printf("%d\n", path[0]); 
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamCycle();

    return 0;
}


____________________________________________________________________________
