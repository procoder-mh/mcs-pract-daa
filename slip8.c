SLIP 8


Q.1) Write a program to implement Fractional Knapsack problems using Greedy Method


#include <stdio.h>

struct Item {
    int value, weight;
    float ratio;
};
 
void sort(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].ratio < arr[j].ratio) {
                struct Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
    }

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].weight);
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sort(arr, n);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i].weight) {
            capacity -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);

    return 0;
}



Q.2) Write Program to implement Traveling Salesman Problem using nearest neighbor
algorithm


#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int cost[MAX][MAX];

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int visited[MAX] = {0};
    int path[MAX];
    int totalCost = 0;

    int current = 0;    
    visited[current] = 1;
    path[0] = current;

    printf("\nPath: %d", current);

    for (int count = 1; count < n; count++) {
        int next = -1;
        int min = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && cost[current][i] != 0 && cost[current][i] < min) {
                min = cost[current][i];
                next = i;
            }
        }

        if (next != -1) {
            visited[next] = 1;
            path[count] = next;
            totalCost += min;
            current = next;

            printf(" -> %d", next);
        }
    }
 
    totalCost += cost[current][0];
    printf(" -> %d", 0);

    printf("\nTotal Cost = %d\n", totalCost);

    return 0;
}


_________________________________________________________________________________________
