Slip 3
Q1) Quick Sort
#include <stdio.h>

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

    scanf("%d",&n);

    int arr[n];

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quickSort(arr,0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
Q2) Prim's Algorithm
#include<stdio.h>

int main()
{
    int cost[10][10], visited[10]={0};
    int i,j,n,ne=1,min,a,b,u,v,mincost=0;

    printf("Enter number of vertices:");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    visited[1]=1;

    while(ne<n)
    {
        min=999;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }

        if(visited[u]==0 || visited[v]==0)
        {
            printf("\nEdge %d:(%d %d) cost:%d",ne++,a,b,min);

            mincost+=min;
            visited[b]=1;
        }

        cost[a][b]=cost[b][a]=999;
    }

    printf("\nMinimum cost=%d",mincost);

    return 0;
}

