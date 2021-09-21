#include<stdio.h>

#define STACK_SIZE 5

int top, s[10], item;

// Push function

void push()
{
    if (top == STACK_SIZE - 1)
    {
        printf("\nStack Overflow \n\n");
        return ;
    }
    top = top + 1;
    s[top] = item;
}

// Pop Function

int pop()

{
    int item_deleted;

    if ( top == -1) return -1;

    item_deleted = s[top];
    top -= 1;
    return item_deleted;
}

// Display Function

void display()

{
    int i ;

    if ( top == -1 )
    {
        printf("\nStack is empty\n\n");
        return ;
    }

    printf("\nContents of the stack \n");

    for ( i = top; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
    //printf("\n");
}

void main()
{
    int choice, del;
    top = -1;
    for ( ; ;)    // Infinite loop
    {
        printf("Enter your choice ");

        printf("\n1 : PUSH\t2: POP\t      3 : DISPLAY  \t4 : EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1 : printf ("Enter the item : ");
                     scanf ("%d", &item);
                     push();
                     break ;

            case 2 : del = pop();
                     if (del == -1)
                        printf("\nStack is Underflow\n\n");
                     else
                        printf("\nItem deleted = %d \n\n", del);
                     break ;

            case 3 : display();
                     break;

            default : exit(0);
        }


    }
}

