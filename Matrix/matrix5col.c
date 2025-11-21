// Col interchange
#include <stdio.h>
#include <math.h>
int main()
{
    float a[5][5], c;
    int m, n, m1, n1, i, j;

    printf("Enter the order of A\n");
    scanf("%d%d", &m, &n);

    printf("Enter the element of A\n");
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);

    printf("Enter the number of two columns to be exchanged \n");
    scanf("%d%d", &m1, &n1);
    for (i = 1; i <= m; ++i)
    {
        c = a[i][n1];
        a[i][n1] = a[i][m1];
        a[i][m1] = c;
    }
    printf("The matrix after interchanging the two columns\n");
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%.1f\t", a[i][j]);
        printf("\n");
    }
}