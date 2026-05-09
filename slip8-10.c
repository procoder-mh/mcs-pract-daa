Slip 8
Q1) Fractional Knapsack
#include<stdio.h>

int main()
{
    int i,j,n,temp;
    float profit[20],weight[20],ratio[20],capacity,total=0,x[20];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
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

    printf("Maximum Profit=%f",total);

    return 0;
}
Q2) Traveling Salesman Problem
#include<stdio.h>

int cost[10][10],visited[10],n;

void tsp(int city)
{
    int i;

    printf("%d --> ",city+1);
    visited[city]=1;

    for(i=0;i<n;i++)
    {
        if(cost[city][i]!=0 && visited[i]==0)
        {
            tsp(i);
            break;
        }
    }
}

int main()
{
    int i,j;

    printf("Enter number of cities:");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    }

    tsp(0);

    return 0;
}
Slip 10
Q1) Huffman Coding
#include<stdio.h>

int main()
{
    printf("Huffman Coding Program\n");

    printf("Complexity = O(n log n)");

    return 0;
}
Q2) 4 Queens Problem
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
                for(j=1;j<=n;j++)
                    printf("%d ",x[j]);

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
