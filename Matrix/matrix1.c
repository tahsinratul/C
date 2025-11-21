// Addition
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, m, n;
    float a[5][5], b[5][5], c[5][5]; // Two dimensional array

    printf("Enter the order of matrices mxn\n");
    scanf("%d%d", &m, &n);

    printf("Enter the Matrix A\n");
    for (i = 1; i <= m; ++i)     // Outer loop for Row m
        for (j = 1; j <= n; ++j) // Inner loop for column n
            scanf("%f", &a[i][j]);

    printf("Enter the Matrix B\n");
    for (i = 1; i <= m; ++i)
        for (j = 1; j <= n; ++j)
            scanf("%f", &b[i][j]);

    for (i = 1; i <= m; ++i)
        for (j = 1; j <= n; ++j)
            c[i][j] = a[i][j] + b[i][j];

    printf("The new matrix C\n");
    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
            printf("%.1f\t", c[i][j]);
        printf("\n");
    }
}