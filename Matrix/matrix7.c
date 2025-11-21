// Square,symmetric,skew-symmetric
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, n;
    float a[5][5], s[5][5], sk[5][5];

    printf("Enter the order of the matrix A\n");
    scanf("%d", &n);

    printf("Enter the element of the matrix A\n");
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            scanf("%f", &a[i][j]);

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            s[i][j] = (a[i][j] + a[j][i]) * 0.5;
    printf("The symmetric matrix of A is\n");
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            printf("%.1f\t", s[i][j]);
        printf("\n");
    }

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            sk[i][j] = (a[i][j] - a[j][i]) * 0.5;
    printf("The skew-symmetric matrix of A is\n");
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            printf("%.1f\t", sk[i][j]);
        printf("\n");
    }
}
