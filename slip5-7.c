Slip 5
Q1) Kruskal Algorithm
#include<stdio.h>

int parent[10];

int find(int i)
{
    while(parent[i])
        i=parent[i];

    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }

    return 0;
}

int main()
{
    int a,b,u,v,n,i,j,ne=1;
    int min,mincost=0,cost[10][10];

    printf("Enter vertices:");
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

    while(ne<n)
    {
        min=999;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u=find(u);
        v=find(v);

        if(uni(u,v))
        {
            printf("\n%d edge (%d,%d)=%d",ne++,a,b,min);

            mincost+=min;
        }

        cost[a][b]=cost[b][a]=999;
    }

    printf("\nMinimum cost=%d",mincost);

    return 0;
}
Q2) Huffman Coding
#include<stdio.h>

int main()
{
    printf("Huffman Coding using Greedy Method\n");

    printf("Best Case Complexity = O(n log n)\n");
    printf("Worst Case Complexity = O(n log n)\n");

    return 0;
}
Slip 7
Q1) Dijkstra Algorithm
#include<stdio.h>

int main()
{
    int cost[10][10],dist[10],visited[10];
    int n,i,j,count,mindistance,nextnode,start;

    printf("Enter number of vertices:");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    printf("Enter starting node:");
    scanf("%d",&start);

    for(i=0;i<n;i++)
    {
        dist[i]=cost[start][i];
        visited[i]=0;
    }

    dist[start]=0;
    visited[start]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=999;

        for(i=0;i<n;i++)
        {
            if(dist[i]<mindistance && !visited[i])
            {
                mindistance=dist[i];
                nextnode=i;
            }
        }

        visited[nextnode]=1;

        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(mindistance+cost[nextnode][i]<dist[i])
                    dist[i]=mindistance+cost[nextnode][i];
            }
        }

        count++;
    }

    printf("Shortest distances:\n");

    for(i=0;i<n;i++)
        printf("%d -> %d = %d\n",start,i,dist[i]);

    return 0;
}
Q2) Topological Sort
#include<stdio.h>

int main()
{
    int n,i,j,a[10][10],indeg[10]={0},flag[10]={0},count=0;

    printf("Enter number of vertices:");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            indeg[i]+=a[j][i];
        }
    }

    printf("Topological order:\n");

    while(count<n)
    {
        for(i=0;i<n;i++)
        {
            if(indeg[i]==0 && flag[i]==0)
            {
                printf("%d ",i);
                flag[i]=1;
            }

            for(j=0;j<n;j++)
            {
                if(a[i][j]==1)
                    indeg[j]--;
            }
        }

        count++;
    }

    return 0;
}
