// Row scalling and addition
#include <stdio.h>
#include <math.h>
int main()
{
    float a[5][5], c, k;
    int m, n, m1, n1, i, j;

    printf("enter the order of the matrix A\n");
    scanf("%d%d", &m, &n);

    printf("enter the element of A\n");
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter the number of the row to be scaled and addition with which row\n");
    scanf("%d%d", &m1, &n1);
    printf("enter scaling value\n");
    scanf("%f", &k);

    for (j = 1; j <= n; ++j)
    {
        c = a[m1][j] + k * a[n1][j];
        a[m1][j] = c;
    }
    printf("the matrix after scaling a row\n");
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%.1f\t", a[i][j]);
        printf("\n");
    }
}