// Jacobi iteration method
#include <stdio.h>
#include <math.h>
int main()
{
    float a[10][10], b[10], x[10][10], s, v = 1;
    int n, i, j, k, p;

    printf("Enter the order of system of equation\n ");
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
        s = 0;
        for (j = 1; j <= n; j++)
            if (i != j)
                s = s + fabs(a[i][j]);
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
            x[0][i] = 0;
        for (k = 1; k <= p; k++)
        {
            for (i = 1; i <= n; i++)
            {
                s = 0;
                for (j = 1; j <= n; j++)
                    if (i != j)
                        s = s + a[i][j] * x[k - 1][j] / a[i][i];
                x[k][i] = (b[i] / a[i][i]) - s;
            }
        }
        printf("The iteration table is \n");
        for (k = 0; k <= p; k++)
        {
            for (i = 1; i <= n; i++)
                printf("%8.5f ", x[k][i]);
            printf("\n\n");
        }
        printf("approximation solution of the system is\n");
        {
            for (i = 1; i <= n; i++)
                printf("x%d=%5.2f\t", i, x[p][i]);
            printf("\n\n");
        }
    }
}