Slip 16
Q1) 0/1 Knapsack using Dynamic Programming
#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;

    return b;
}

int main()
{
    int i,w,n,m;
    int p[10],wt[10],v[10][10];

    printf("Enter number of items:");
    scanf("%d",&n);

    printf("Enter profits:\n");

    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);

    printf("Enter weights:\n");

    for(i=1;i<=n;i++)
        scanf("%d",&wt[i]);

    printf("Enter capacity:");
    scanf("%d",&m);

    for(i=0;i<=n;i++)
    {
        for(w=0;w<=m;w++)
        {
            if(i==0 || w==0)
                v[i][w]=0;

            else if(wt[i]<=w)
                v[i][w]=max(p[i]+v[i-1][w-wt[i]],v[i-1][w]);

            else
                v[i][w]=v[i-1][w];
        }
    }

    printf("Maximum Profit=%d",v[n][m]);

    return 0;
}
Q2) Hamiltonian Cycle
#include<stdio.h>

int x[10];

int place(int k,int i,int graph[10][10])
{
    int j;

    if(graph[x[k-1]][i]==0)
        return 0;

    for(j=1;j<k;j++)
    {
        if(x[j]==i)
            return 0;
    }

    return 1;
}

void hamiltonian(int k,int n,int graph[10][10])
{
    int i,j;

    while(1)
    {
        x[k]=(x[k]+1)%(n+1);

        if(x[k]==0)
            return;

        if(place(k,x[k],graph))
        {
            if(k==n)
            {
                if(graph[x[n]][x[1]]!=0)
                {
                    for(j=1;j<=n;j++)
                        printf("%d ",x[j]);

                    printf("%d",x[1]);
                    printf("\n");
                }
            }
            else
                hamiltonian(k+1,n,graph);
        }
    }
}

int main()
{
    int graph[10][10],i,j,n;

    printf("Enter number of vertices:");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&graph[i][j]);
    }

    x[1]=1;

    hamiltonian(2,n,graph);

    return 0;
}

