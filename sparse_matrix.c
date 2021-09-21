#include<stdio.h>
#include<stdlib.h>

int k;
typedef struct
{
    int row,col,val;
}TERM;

//FUNCTION TO READ SPARSE MATRIX AS A TRIPLE

void read_sparse_matrix(TERM a[],int m,int n)
{
    int i,j,item;
    a[0].row=m;
    a[0].col=n;
    k=1;
    printf("Enter the elements \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&item);
            if(item==0) continue;
            a[k].row=i;
            a[k].col=j;
            a[k].val=item;
            printf("Non zero element is stored in location a[%d].val = %d\n",k,a[k].val);
            k++;
        }
    }
    a[0].val=k-1;   // Total no. of non zeros in sparse matrix

}
void print_sparse_matrix(TERM a[])
{
    int p;
    printf("\nNon zero elements are present in the following locations \n\n");
    for(p=1;p<k;p++)
    {
        printf("row = %d    col = %d    val = %d\n\n",a[p].row,a[p].col,a[p].val);
    }
}
//FUNCTION TO SEARCH FOR AN ITEM IN SPARSE MATRIX
void search(TERM a[],int item)
{
    int i,j;
    for(i=0;i<k;i++)
    {
        if(item==a[i].val)
        {
            printf("\nSearch is successful\nElement is found at pos : %d\n",i);
            exit(0);
        }
    }
    printf("\n\nSearch is unsuccessful......\n\n");

}
void main()
{
    int m,n,item;
    TERM a[20];

    printf("Enter the number of Rows & Columns\n");
    scanf("%d %d",&m,&n);

    read_sparse_matrix(a,m,n);

    print_sparse_matrix(a);

    printf("Enter the element to be searched : ");
    scanf("%d",&item);

    search(a,item);
}
