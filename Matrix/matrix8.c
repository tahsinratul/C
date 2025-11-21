// Matrix polynomial A^2+2A-11I
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, k, n;
    float a[5][5], I[5][5], c[5][5], f[5][5], m[5][5];

    printf("enter the order of the square matrix A\n");
    scanf("%d", &n);

    printf("enter the element of the matrix A\n");
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            scanf("%f", &a[i][j]);

    printf("enter the identity matrix I\n");
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            scanf("%f", &I[i][j]);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            c[i][j] = 0;
            for (k = 1; k <= n; k++)
                c[i][j] = c[i][j] + a[i][k] * a[k][j];
        }
    }

    /*
        for cubic equation
        for(i=1;i<=n;i++)
        {
        for(j=1;j<=n;j++)
        {
        f[i][j]=0;
        for(k=1;k<=n;k++)
        f[i][j]=f[i][j]+c[i][k]*a[k][j];
        }
        }
    */

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            m[i][j] = c[i][j] + 2 * a[i][j] - 11 * I[i][j];
    printf("the matrix polynomial\n");
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
            printf("%.1f\t", m[i][j]);
        printf("\n");
    }
}