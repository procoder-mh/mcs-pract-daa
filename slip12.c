Slip 12
Q1) BFS
#include<stdio.h>

int main()
{
    int a[10][10],visited[10]={0},queue[10];
    int i,j,n,v,front=0,rear=-1;

    printf("Enter number of vertices:");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }

    printf("Enter starting vertex:");
    scanf("%d",&v);

    queue[++rear]=v;
    visited[v]=1;

    while(front<=rear)
    {
        v=queue[front++];

        printf("%d ",v);

        for(i=0;i<n;i++)
        {
            if(a[v][i]==1 && visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }

    return 0;
}
Q2) Selection Sort
#include<stdio.h>

int main()
{
    int a[100],n,i,j,min,temp;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }

    printf("Sorted Array:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}

