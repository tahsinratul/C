// Transpose matrix
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, m, n;
    float a[5][5], b[5][5]; // Two dimensional array

    printf("Enter the order of matrix A\n");
    scanf("%d%d", &m, &n);

    printf("Enter the Matrix A\n");
    for (i = 1; i <= m; ++i)     // Outer loop for Row m
        for (j = 1; j <= n; ++j) // Inner loop for column n
            scanf("%f", &a[i][j]);

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            b[i][j] = a[j][i];
    printf("the transpose of A\n");

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
            printf("%.1f\t", b[i][j]);
        printf("\n");
    }
}