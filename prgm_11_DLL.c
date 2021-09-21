//C PROGRAM TO CREATE A CIRCULAR DOUBLY LINKED LIST AND TO DISPLAY THE CONTENTS OF THE LIST
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
//STRUCTURE DEFINITION
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
//FUNCTION TO CREATE NEW NODES DYNAMICALLY
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("OUT OF MEMORY\n");
        getch();
        exit(0);
    }
    return x;
}
//FUNCTION TO INSERT NEW NODES FROM FRONT END
NODE insertfront(int item, NODE head)
{
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    cur = head->rlink;
    head->rlink = temp;
    temp->llink = head;
    temp->rlink = cur;
    cur->llink = temp;
    return head;
}
//FUNCTION TO INSERT NEW NODES BEFORE THE KEY ELEMENT SPECIFIED
NODE insertleft(int item, NODE head)
{
    NODE temp, cur, prev;
    if (head->rlink == head)
    {
        printf("LIST IS EMPTY...\n");
        return head;
    }
    cur = head->rlink;
    while (cur != head)
    {
        if (item == cur->info)
            break;
        cur = cur->rlink;
    }
    if (cur == head)
    {
        printf("Key not found\n");
        return head;
    }
    prev = cur->llink;
    printf("Enter the item to insert towards left of %d = ", item);
    scanf("%d", &item);
    temp = getnode();
    temp->info = item;
    prev->rlink = temp;
    temp->llink = prev;
    cur->llink = temp;
    temp->rlink = cur;
    return head;
}
//FUNCTION TO IDELTE THE KEY ELEMENT SPECIFIED
NODE deleteitem(int item, NODE head)
{
    NODE cur, prev, next;
    if (head->rlink == head)
    {
        printf("List is empty, cannot delete\n");
        return head;
    }
    cur = head->rlink;
    while (cur != head)
    {
        if (item == cur->info)
            break;
        cur = cur->rlink;
    }
    if (cur == head)
    {
        printf("ITEM NOT FOUND\n");
        return head;
    }
    prev = cur->llink;
    next = cur->rlink;
    prev->rlink = next;
    next->llink = prev;
    free(cur);
    return head;
}
//FUNCTION TO DISPLAY THE CONTENTS OF THE DLL
void display(NODE head)
{
    NODE temp;
    if (head->rlink == head)
    {
        printf("List is Empty\n");
        return;
    }
    printf("CONTENTS OF THE CIRCULAR DOUBLY LINKED LIST :\n");
    temp = head->rlink;
    while (temp != head)
    {
        printf("%d\n", temp->info);
        temp = temp->rlink;
    }
}
//MAIN FUNCTION
void main()

{
    NODE head;
    int choice, item;
    head = getnode();
    head->rlink = head;
    head->llink = head;
    for (;;)
    {
        printf("\n1 : INSERT_FRONT\t2 : INSERT_LEFT_KEY\t3 : DELETE_KEY\t4 : DISPLAY\t5 : QUIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            head = insertfront(item, head);
            break;
        case 2:
            printf("Enter the key element : ");
            scanf("%d", &item);
            head = insertleft(item, head);
            break;
        case 3:
            printf("Enter the item to be deleted : ");
            scanf("%d", &item);
            head = deleteitem(item, head);
            break;
        case 4:
            display(head);
            break;
        default:
            exit(0);
        }
    }
}
