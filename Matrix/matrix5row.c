// Row interchange
#include <stdio.h>
#include <math.h>
int main()
{
    float a[5][5], r;
    int m, n, m1, n1, i, j;

    printf("Enter the order of A\n");
    scanf("%d%d", &m, &n);

    printf("Enter the element of A\n");
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter the number of two rows to be exchanged \n");
    scanf("%d%d", &m1, &n1);
    for (j = 1; j <= n; ++j)
    {
        r = a[m1][j];
        a[m1][j] = a[n1][j];
        a[n1][j] = r;
    }
    printf("The matrix after interchanging the two rows\n");
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%.1f\t", a[i][j]);
        printf("\n");
    }
}