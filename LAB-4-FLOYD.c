#include <stdio.h>

#define MAX 10
#define INF 99999 

int a[MAX][MAX], D[MAX][MAX], n;

void floyd(int [][MAX], int);
int min(int, int);

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use %d to represent infinity):\n", INF);

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    floyd(a, n);

    printf("Distance Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void floyd(int a[][MAX], int n)
{
    int i, j, k;

   
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            D[i][j] = a[i][j];
        }
    }

  
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}
