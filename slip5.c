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
