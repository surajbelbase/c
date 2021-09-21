#include<stdio.h>

int search(int key, int a[], int low, int high);

void main()

{
    int n, i, a[20], key, pos;

    printf("\nEnter the number of elements : ");
    scanf("%d", &n);

    printf("\nEnter the elements\n\n");

    for (i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the key element to be searched : ");
    scanf("%d", &key);

    pos = search(key, a, 0, n-1);

    if (pos == -1)
        printf("\nKey element is not  found.......\n");

    else
        printf("\nElement found at position %d\n",pos);

    return 0;
}

int search(int key, int a[], int low, int high)
{
    int mid;

    if ( low > high )return -1;
        mid = (low + high)/2;

    if ( key == a[mid] )
        return mid;

    if ( key < a[mid] )
        search(key, a, low,  mid-1);

    else
        search(key, a, mid+1, high);
}
