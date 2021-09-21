#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 20
//FUNCTION TO CREATE A MAXHEAP
int maxheap(int item, int a[], int n)
{
    int c, p;
    if (n == MAXSIZE - 1)
    {
        printf("HEAP IS FULL\n");
        return n - 1;
    }
    c = n;
    p = c / 2;
    while (p != 0 && item > a[p])
    {
        a[c] = a[p];
        c = p;
        p = c / 2;
    }
    a[c] = item;
    return n;
}
void display(int a[], int n)
{
    int i;
    if (n == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    printf("\nCONTENTS OF THE HEAP : \n");
    for (i = 1; i <= n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
//MAIN FUNCTION
void main()
{
    int a[100], n = 0, choice, item;
    for (;;)
    {
        printf("\n1 : INSERT\t2 : DISPLAY\t3 : EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item : ");
            scanf("%d", &item);
            n = maxheap(item, a, n + 1);
            break;
        case 2:
            display(a, n);
            break;
        default:
            exit(0);
        }
    }
    getch();
}