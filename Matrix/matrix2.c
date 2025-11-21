// Multiplication
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, m, n, p, q, k;
    float a[5][5], b[5][5], c[5][5]; // Two dimensional array

    printf("Enter the order of matrices A\n");
    scanf("%d%d", &m, &n);

    printf("Enter the order of matrices B\n");
    scanf("%d%d", &p, &q);

    if (n == p)
    {
        printf("Enter the Matrix A\n");
        for (i = 1; i <= m; ++i)     // Outer loop for Row m
            for (j = 1; j <= n; ++j) // Inner loop for column n
                scanf("%f", &a[i][j]);

        printf("Enter the Matrix B\n");
        for (i = 1; i <= p; ++i)
            for (j = 1; j <= q; ++j)
                scanf("%f", &b[i][j]);

        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= q; j++)
            {
                c[i][j] = 0;
                for (k = 1; k <= n; k++)
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
        printf("the multiplication of A and B\n");

        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= q; j++)
                printf("%.1f\t", c[i][j]);
            printf("\n");
        }
    }
    else
        printf("the multiplication of A and B is not possible\n");
}