// Second derivative
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, n, k;
    float x[20], y[20], d[20][20], u, sum, a, h, b;
    int fact(int k);
    float f(float x, int n, int i);
    float df(float x, int n);
    printf("enter how many pairs of values of x and y are in there\n");
    scanf("%d", &n);
    printf("enter the first value of x\n");
    scanf("%f", &x[0]);
    printf("enter the common difference\n");
    scanf("%f", &h);
    for (i = 0; i < n - 1; ++i)
        x[i + 1] = x[i] + h;
    printf("enter the values of y\n", n);
    for (i = 0; i < n; ++i)
        scanf("%f", &y[i]);
    for (i = 0; i < n; ++i)
        d[0][i] = y[i];
    printf("the difference table is:\n");
    for (i = 1; i < n; ++i)
    {
        for (j = 0; j < n - i; ++j)
        {
            d[i][j] = d[i - 1][j + 1] - d[i - 1][j];
            printf("d[%d][%d]=%f\t", i, j, d[i][j]);
        }
        printf("\n");
    }
    printf("enter the value of x where the value of y is to be interpolated\n");
    scanf("%f", &a);
    u = (a - x[0]) / h;
    sum = 0.0;
    for (i = 1; i < n; ++i)
        sum = sum + df(u, i) * d[i][0] / fact(i);
    printf("The first derivative of f at %f=%f\n", a, sum / h);
    for (j = 0; j < n; ++j)
    {
        b = x[j];
        u = (b - x[0]) / h;
        sum = 0.0;
        for (i = 1; i < n; ++i)
            sum = sum + df(u, i) * d[i][0] / fact(i);
        y[j] = sum / h;
    }
    for (i = 0; i < n; ++i)
        d[0][i] = y[i];
    for (i = 1; i < n; ++i)
        for (j = 0; j < n - i; ++j)
            d[i][j] = d[i - 1][j + 1] - d[i - 1][j];
    u = (a - x[0]) / h;
    sum = 0.0;
    for (i = 1; i < n; ++i)
        sum = sum + df(u, i) * d[i][0] / fact(i);
    printf("The second derivative of f at %f=%f\n", a, sum / h);
}
int fact(int k)
{
    int prod = 1, i;
    for (i = 1; i <= k; ++i)
        prod = prod * i;
    return (prod);
}
float f(float p, int n, int i)
{
    float prod = 1.0;
    int j;
    for (j = 0; j < n; ++j)
        if (j != i - 1)
            prod = prod * (p - j);
    return (prod);
}
float df(float x, int n)
{
    int i;
    float sum = 0.0;
    for (i = 1; i <= n; ++i)
        sum = sum + f(x, n, i);
    return (sum);
}