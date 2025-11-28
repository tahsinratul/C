// Jacobi iteration method
#include <stdio.h>
#include <math.h>
int main()
{
    float a[10][10], b[10], d[10][10], s = 0.0, v = 1;
    int n, i, j, k, p;

    printf("Enter the order of system of equation\n");
    scanf("%d", &n);

    printf("Enter the coefficient matrix \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter the constants \n");
    for (i = 1; i <= n; i++)
        scanf("%f", &b[i]);

    printf("Enter the number of iteration \n");
    scanf("%d", &p);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i != j)
                s = s + fabs(a[i][j]);
        }
        if (fabs(a[i][i]) <= s)
        {
            v = 0;
            break;
        }
    }

    if (v == 0)
        printf("The method diverges\n");
    else
    {
        for (i = 1; i <= n; i++)
            d[0][i] = 0;
        for (k = 1; k <= p; k++)
        {
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                    if (i != j)
                        s = s + a[i][j] * d[k - 1][j] / a[i][i];
                d[k][i] = (b[i] / a[i][i]) - s;
            }
        }
        printf("The iteration table is \n");
        for (k = 0; k <= p; k++)
        {
            for (i = 1; i <= n; i++)
                printf("%f\t ", d[k][i]);
            printf("\n\n");
        }
        printf("approximation solution of the system is\n");
        for (i = 1; i <= n; i++)
            printf("x%d=%f\t", i, d[p][i]);
    }
}