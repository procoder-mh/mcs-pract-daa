Design and Analysis of Algorithms 

_______________________________________________________________________________________________
  
           
               SLIP 1

Q.1) Write a program to sort a list of n numbers in ascending order using selection sort and
determine the time required to sort the elements .


#include <stdio.h>
#include <time.h>

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
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}



Q.2) Write a program to sort a given set of elements using the Quick sort method and determine
the time required to sort the elements. Repeat the experiment for different values of n, the
number of elements in the list to be sorted. The elements can be read from a file or can be
generated using the random number generator.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1, j, temp;

        for (j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}


______________________________________________________________________________________________


    clock_t start, end;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    printf("Sorted Array:\n");

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    double time_taken = (double)(end - start)/CLOCKS_PER_SEC;

    printf("\nTime Taken = %f", time_taken);

    return 0;
}
