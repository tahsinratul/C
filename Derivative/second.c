// Second derivative
#include <stdio.h>
#include <math.h>
int main()
{
    int i, j, n, k;
    float x[20], y[20], d[20][20], u, sum, a, h, b;
    int fact(int k);
    float fr(float x, int n, int i);
    float df(float x, int n);
    printf("enter how many pairs of values of x and y are in there");
    scanf("%d", &n);
    printf("enter the first value of x\n");
    scanf("%f", &x[0]);
    printf("enter the common difference of x values \n");
    scanf("%f", &h);
    for (i = 0; i < n - 1; ++i)
        x[i + 1] = x[i] + h;
    printf("enter %d y values \n", n);
    for (i = 0; i < n; ++i)
        scanf("%f", &y[i]);
    for (i = 0; i < n; ++i)
        d[0][i] = y[i];
    for (i = 1; i < n; ++i)
        for (j = 0; j < n - i; ++j)
            d[i][j] = d[i - 1][j + 1] - d[i - 1][j];
    printf("enter the value of x where the value of y is to be interpolated\n");
    scanf("%f", &a);
    u = (a - x[0]) / h;
    sum = 0.0;
    for (i = 1; i < n; ++i)
        sum = sum + df(u, i) * d[i][0] / fact(i);
    printf("enter the firet derivative of f at %f=%f\n", a, sum / h);
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
    printf(" the second derivative of f at %f=%f\n", a, sum / h);
}
int fact(int k)
{
    int prod = 1, i;
    for (i = 1; i <= k; ++i)
        prod = prod * i;
    return (prod);
}
float fr(float x, int n, int i)
{
    int j;
    float prod = 1.0;
    for (j = 0; j < i - 1; ++j)
        prod = prod * (x - j);
    for (j = i; j < n; ++j)
        prod = prod * (x - j);
    return (prod);
}
float df(float x, int n)
{
    int i;
    float sum = 0.0;
    for (i = 1; i <= n; ++i)
        sum = sum + fr(x, n, i);
    return (sum);
}