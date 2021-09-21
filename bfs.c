#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void BFS(int a[20][20], int source, int visited[20], int n)
{
    int queue[20], f, r, u, v;
    f = 0;
    r = -1;
    queue[++r] = source;
    while (f <= r)
    {
        u = queue[f++];
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] && visited[v] == 0)
            {
                queue[++r] = v;
                visited[v] = 1;
            }
        }
    } // end of while loop
} // end of function BFS

void main()
{
    int n, a[20][20], visited[20], i, j, source;
    char ch;
    system("cls");
repeat:
    for (;;)
    {
        printf("\nEnter the number of vertices : ");
        scanf("%d", &n);
        printf("\nEnter the adjacency matrix : \n");
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        }
        for (i = 1; i <= n; i++)
        {
            visited[i] = 0;
        }
        printf("\nEnter the source node : ");
        scanf("%d", &source);
        visited[source] = 1;
        BFS(a, source, visited, n);
        printf("The nodes reachable from source node %d --> ", source);
        for (i = 1; i <= n; i++)
        {
            if (visited[i] && i != source)
                printf("\nNode %d is reachable", i);
        }
        fflush(stdin);
        printf("\nDo you want to continue... ");
        scanf("%c", &ch);
        if (ch == 'y')
            goto repeat;
        else
            break;
    } // end infinite for loop
    getch();
}
