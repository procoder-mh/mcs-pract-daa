SLIP 19



Q.1) Write a program to determine if a given graph is a Hamiltonian cycle or not.


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



Q.2) Write a program to show board configuration of 4 queens’ problem.



#include <stdio.h>
#define N 4

int board[N][N];
 
int isSafe(int row, int col) {
    int i, j;
 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;
 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
 
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}
 
int solve(int col) {
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            if (solve(col + 1))
                return 1;

            board[i][col] = 0;  
        }
    }
    return 0;
}
 
void printBoard() {
    printf("Board Configuration (1 = Queen, 0 = Empty):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
     
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solve(0)) {
        printBoard();
    } else {
        printf("No solution exists\n");
    }

    return 0;
}

_____________________________________________________________________________-
