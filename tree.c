#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
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
//Function to insert items into a binary search tree
NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    temp = getnode();
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item == cur->info)
        {
            printf("Duplicate items not allowed\n");
            free(temp);
            return root;
        }
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}
//Fuction to display the tree
void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}
void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}
void main()
{
    NODE root;
    int choice, item, x;
    root = NULL;
    for (;;)
    {
        printf("\n1 : INSERT\t2 : DISPLAY, PREORDER + INORDER + POSTORDER\t3 : EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            if (root == NULL)
                printf("Tree is empty\n");
            else
            {
                printf("PREOREDER TRAVERSAL  : ");
                preorder(root);
                // printf("\n");
                printf("\nINOREDER TRAVERSAL   : ");
                inorder(root);
                // printf("\n");
                printf("\nPOSTOREDER TRAVERSAL : ");
                postorder(root);
                printf("\n");
            }
            break;
        default:
            exit(0);
        }
    }
}