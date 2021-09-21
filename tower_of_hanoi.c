#include<stdio.h>

#include<stdio.h>

void tower (int n, char src, char temp, char des)

{
    if (n == 0)
        return;

    tower (n-1, src, des, temp);

    printf("\nMove disc %d from %c to %c\n", n, src, des);

    tower (n-1, temp, src, des);
}

int main()

{
    int n;

    printf("Enter the numbers of disks : ");
    scanf("%d", &n);

    tower (n, 'P', 'Q', 'R');

    return 0;
}
