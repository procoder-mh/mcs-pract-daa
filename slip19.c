Slip 19
Q1) Hamiltonian Cycle
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

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&graph[i][j]);
    }

    x[1]=1;

    hamiltonian(2,n,graph);

    return 0;
}
Q2) 4 Queens Board Configuration
#include<stdio.h>

int x[10];

int place(int k,int i)
{
    int j;

    for(j=1;j<k;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return 0;
    }

    return 1;
}

void queen(int k,int n)
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;

            if(k==n)
            {
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                    {
                        if(x[i]==j)
                            printf("Q ");
                        else
                            printf("* ");
                    }

                    printf("\n");
                }

                printf("\n");
            }
            else
                queen(k+1,n);
        }
    }
}

int main()
{
    queen(1,4);

    return 0;
}
