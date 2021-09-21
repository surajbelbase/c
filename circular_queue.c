#include<stdio.h>
#include<process.h>
#define QSIZE 3
int item, f, r, count, q[20];

void insert_rear()
{
    if (count == QSIZE)
    {
        printf("\nQueue is overflow.....\n");
        return ;
    }
    r = (r + 1)%QSIZE;
    q[r] = item;
    count = count + 1;
}

void delete_front()
{
    if (count == 0)
    {
        printf("\nQueue is underflow.....\n");
        return ;
    }
    printf("\nDeleted element = %d\n",q[f]);
    f = (f + 1)%QSIZE;
    count = count - 1;
}

void display()
{
    int i;
    int temp = f;
    if (count == 0)
    {
        printf("\nQueue is empty.....\n");
        return;
    }
    printf("\nContents of queue : \n");

    for (i = 1; i<= count; i++)
        {
            printf("\nValue of front == %d and q[%d] = %d",temp,temp,q[temp]);
            temp = ( temp + 1 )%QSIZE;
        }
    printf("\n");
}

void main()
{
    int choice;
    f = 0;
    r = -1;
    count = 0;
    for( ; ; )
        {
            printf("\n1 : INSERT\t2 : DELETE\t3 : DISPLAY\t4 : EXIT\n");
            printf("Enter the choice : ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1 : printf("Enter the item to be inserted : ");
                         scanf("%d", &item);
                         insert_rear();
                         break;

                case 2 : delete_front();
                         break;

                case 3 : display();
                         break;

                default : exit(0);
            }
        }
}
