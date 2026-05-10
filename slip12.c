SLIP 12


Q.1) Write a program to implement BFS (Breadth First Search) and determine the time
complexity for the same.


#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = -1;
int visited[MAX];
 
void enqueue(int v) {
    queue[++rear] = v;
}
 
int dequeue() {
    return queue[front++];
}
 
int isEmpty() {
    return front > rear;
}
 
void BFS(int graph[MAX][MAX], int V, int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < V; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int V, start;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);
 
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    BFS(graph, V, start);

    return 0;
}



Q.2) Write a program to sort a given set of elements using the Selection sort method and
determine the time required to sort the elements.

 
#include <stdio.h>
#include <time.h>

// Selection Sort function
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
 
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;

    start = clock();
    selectionSort(arr, n);
    end = clock();

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}


______________________________________________________________________________

