#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("OUT OF MEMORY\n");
        getch();
        exit(0);
    }
    return x;
}

NODE insertrear(int item,NODE first)
{
    NODE temp;
    NODE cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}

NODE deletefront(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("\nList is empty, cannot delete\n");
        return first;
    }
    temp=first;
    temp=temp->link;
    printf("\nItem deleted is %d\n",first->info);
    free(first);
    first=NULL;
    return temp;
}

void display(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY...\n");
        return;
    }
    printf("\nCONTENTS OF SINGLY LINKED LIST :\n");
    temp=first;
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->link;
    }
    printf("\n");
}

void main()
{
    NODE first=NULL;
    int choice,item;
    system("cls");
    for(;;)
    {
        printf("\n1 : INSERT_REAR    2 : DELETE_FRONT\t3 : DISPLAY\t4 : QUIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the item to be inserted : ");
                    scanf("%d",&item);
                    first=insertrear(item,first);
                    break;

            case 2: first=deletefront(first);
                    break;

            case 3: display(first);
                    break;

            default: exit(0);
        }
    }
}
