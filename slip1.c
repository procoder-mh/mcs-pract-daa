Slip 1
Q1) Selection Sort
#include <stdio.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;

    start = clock();
    selectionSort(arr, n);
    end = clock();

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    double time_taken = (double)(end - start)/CLOCKS_PER_SEC;

    printf("\nTime Taken = %f", time_taken);

    return 0;
}
Q2) Quick Sort
#include <stdio.h>
#include <time.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

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
