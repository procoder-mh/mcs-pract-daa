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
Slip 4
Q1) Merge Sort
#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int i,j,k,b[100];

    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }

    while(i<=mid)
        b[k++]=a[i++];

    while(j<=high)
        b[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=b[i];
}

void mergesort(int a[],int low,int high)
{
    int mid;

    if(low<high)
    {
        mid=(low+high)/2;

        mergesort(a,low,mid);
        mergesort(a,mid+1,high);

        merge(a,low,mid,high);
    }
}

int main()
{
    int a[100],n,i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    mergesort(a,0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
Q2) Greedy Knapsack
#include<stdio.h>

int main()
{
    int i,j,n,temp;
    float profit[20],weight[20],ratio[20],capacity,total=0,x[20];

    printf("Enter number of objects:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Profit and Weight:");
        scanf("%f%f",&profit[i],&weight[i]);

        ratio[i]=profit[i]/weight[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;
            }
        }
    }

    printf("Enter capacity:");
    scanf("%f",&capacity);

    for(i=0;i<n;i++)
    {
        if(weight[i]>capacity)
            break;

        x[i]=1.0;
        total+=profit[i];
        capacity-=weight[i];
    }

    if(i<n)
    {
        x[i]=capacity/weight[i];
        total+=x[i]*profit[i];
    }

    printf("Maximum profit=%f",total);

    return 0;
}
