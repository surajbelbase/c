#include<stdio.h>

#define QSIZE 5

int item, f, r, q[5]; // Global variable declaration

void insert_rear()
{
    if( r == QSIZE - 1)
    {
        printf("\nQueue is Overflow\n\n");
        return;
    }
    r = r + 1;
    q[r] = item;
}   // end of rear function

void delete_front()
{
    if (f > r)
    {
        printf ("\nQueue is underflow\n\n");
        return;
    }

    printf("\nElement Deleted is %d\n\n", q[f]);
    f++ ;
}

void display()
{
    int i ;

    if ( f > r )
    {
        printf ("\nQueue is empty\n\n");
        return ;
    }
    printf("\nContents of the queue \n");

    for ( i = f; i <= r; i++)
    {
        printf("%d\n", q[i]);
    }
}

void main()
{
    int choice;
    f = 0;
    r = -1;
    for ( ; ; )
    {
        printf("Enter your choice");

        printf("\n1 : INSERT\t2: DELETE\t3 : DISPLAY\t4 : EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
             case 1 : printf ("Enter the item : ");
                     scanf ("%d", &item);
                     insert_rear();
                     break ;

            case 2 : delete_front();
                     break ;

            case 3 : display();
                     break;

            default : exit(0);

        }   //  END OF SWITCH
    }   // End of for loop
}
