// First derivative
#include <stdio.h>
#include <math.h>

int main()
{
    float f(float, int, int);
    float df(float, int);
    int fact(int);
    float x[100], y[100], d[100][100], a, h, p, sum = 0.0, t_sum;
    int i, n, j;
    printf("enter the number of data n=\t");
    scanf("%d", &n);
    printf("enter the initial value of x=\t");
    scanf("%f", &x[0]);
    printf("enter the distances between x values h=\t");
    scanf("%f", &h);
    for (i = 1; i < n; ++i)
        x[i] = x[i - 1] + h;
    printf("enter the values of y:\n");
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
    printf("enter the value of the point where we want to find the first derivative vale a=\t");
    scanf("%f", &a);
    p = (a - x[0]) / h;
    for (i = 1; i < n; ++i)
        sum = sum + df(p, i) * d[i][0] / fact(i);
    t_sum = sum / h;
    printf("the required first derivative value at %f is %f\n", a, t_sum);
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
float df(float p, int n)
{
    float sum = 0.0;
    int i;
    for (i = 1; i <= n; ++i)
        sum = sum + f(p, n, i);
    return (sum);
}
int fact(int k)
{
    int prod = 1, i;
    for (i = 1; i <= k; ++i)
        prod = prod * i;
    return (prod);
}