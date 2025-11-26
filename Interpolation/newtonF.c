// Newton forward
#include <stdio.h>
#include <math.h>
int main()
{
    float f(float, int);
    int fact(int);
    float x[10], y[10], d[10][10], p, a, sum = 0.0, h, tsum;
    int i, j, n;
    printf("enter the number of data\n");
    scanf("%d", &n);
    printf("enter the initial value of x\n");
    scanf("%f", &x[0]);
    printf("enter the differences\n");
    scanf("%f", &h);
    for (i = 1; i < n; i++)
    {
        x[i] = x[i - 1] + h;
    }
    printf("enter the value of y\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i]);
    for (i = 0; i < n; i++)
        d[0][i] = y[i];
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            d[i][j] = d[i - 1][j + 1] - d[i - 1][j];
            printf("d[%d][%d]=%f\t", i, j, d[i][j]);
        }
        printf("\n\n");
    }
    printf("enter the value where we interpolate y\n");
    scanf("%f", &a);
    p = (a - x[0]) / h;
    for (i = 1; i < n; i++)
    {
        sum = sum + (f(p, i) * d[i][0]) / fact(i);
        printf("%f\n", sum);
    }
    tsum = y[0] + sum;
    printf("the required value is y[%.4f]=%.4f\n", a, tsum);
    return (0);
}
float f(float x, int i)
{
    int l;
    float prod = x;
    for (l = 1; l < i; l++)
        prod = prod * (x - l);
    return (prod);
}
int fact(int k)
{
    int i, prod = 1;
    for (i = 1; i <= k; i++)
        prod = prod * i;
    return (prod);
}